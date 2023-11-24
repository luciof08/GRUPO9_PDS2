#include "RepositorioReserva.hpp"
#include "Reserva.hpp"
#include "UsuarioCliente.hpp"
#include "Quarto.hpp" 
#include "Hotel.hpp" 
#include <pqxx/pqxx>
#include <chrono>
#include <iostream>

std::vector<Reserva> RepositorioReserva::listarReservas(const std::unique_ptr<UsuarioCliente>& usuario) {
    std::vector<Reserva> reservas;

    try {
        pqxx::connection conn("dbname=" + conexao.getDBName() + " user=" + conexao.getUser() + " password=" + conexao.getPassword() + " host=" + conexao.getHost());
        if (conn.is_open()) {
            pqxx::work txn(conn);

            std::string query = "SELECT r.id, r.data_inicio, r.data_fim, q.id AS quarto_id, q.numero AS quarto_numero, qc.id AS usuario_id, qc.nome AS usuario_nome, h.id AS hotel_id, h.nome AS hotel_nome, h.cnpj as hotel_cnpj FROM reserva r \
                                            INNER JOIN quarto q ON r.quarto_id = q.id \
                                            INNER JOIN usuario_cliente qc ON r.usuario_cliente_id = qc.id \
                                            INNER JOIN hotel h ON q.hotel_id = h.id \
                                            WHERE qc.id = " + txn.quote(usuario->getId());
            

            pqxx::result result = txn.exec(query);

            for (const auto &row : result) {
                int id = row["id"].as<int>();

                // Conversão de datas
                std::string dataInicioStr = row["data_inicio"].as<std::string>();
                std::string dataFimStr = row["data_fim"].as<std::string>();
                
                std::tm tmDataInicio = {};
                std::tm tmDataFim = {};
                
                if (strptime(dataInicioStr.c_str(), "%Y-%m-%d", &tmDataInicio) == nullptr ||
                    strptime(dataFimStr.c_str(), "%Y-%m-%d", &tmDataFim) == nullptr) {
                    throw std::runtime_error("Erro ao converter datas.");
                }

                std::time_t timeDataInicio = mktime(&tmDataInicio);
                std::time_t timeDataFim = mktime(&tmDataFim);

                std::chrono::time_point<std::chrono::system_clock> dataInicio = std::chrono::system_clock::from_time_t(timeDataInicio);
                std::chrono::time_point<std::chrono::system_clock> dataFim = std::chrono::system_clock::from_time_t(timeDataFim);

                // Obtenha os outros campos necessários
                int quartoId = row["quarto_id"].as<int>();
                int quartoNumero = row["quarto_numero"].as<int>();

                // Crie um objeto hotel
                std::string nomeHotel = row["hotel_nome"].as<std::string>();
                std::string cnpjHotel = row["hotel_cnpj"].as<std::string>();
                Hotel hotel(nomeHotel, "", cnpjHotel, "");

                // Crie um objeto Quarto
                Quarto quarto(quartoId, quartoNumero, hotel);

                // Crie um objeto UsuarioCliente
                UsuarioCliente usuarioCliente(usuario->getNome(), usuario->getEmail(), usuario->getCPF(), usuario->getSenha());

                // Crie um objeto Reserva e adicione à lista
                Reserva reserva(id, quarto, dataInicio, dataFim, usuarioCliente);
                reservas.push_back(reserva);
            }

            txn.commit();
        } else {
            throw std::runtime_error("Erro ao conectar ao banco de dados.");
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        throw std::runtime_error(e.what());
    }

    return reservas;
}

void RepositorioReserva::incluir(const Reserva& reserva) { 
    try {
        pqxx::connection conn("dbname=" + conexao.getDBName() + " user=" + conexao.getUser() + " password=" + conexao.getPassword() + " host=" + conexao.getHost());
        if (conn.is_open()) {
           pqxx::work txn(conn);

            // Conversão de std::chrono::time_point para std::tm
            std::time_t timeDataInicio = std::chrono::system_clock::to_time_t(reserva.getDataInicio());
            std::time_t timeDataFim = std::chrono::system_clock::to_time_t(reserva.getDataFim());

            std::tm tmDataInicio = *std::localtime(&timeDataInicio);
            std::tm tmDataFim = *std::localtime(&timeDataFim);

            // Formatação das datas para o formato 'YYYY-MM-DD'
            char dataInicioStr[11];
            char dataFimStr[11];

            std::strftime(dataInicioStr, sizeof(dataInicioStr), "%Y-%m-%d", &tmDataInicio);
            std::strftime(dataFimStr, sizeof(dataFimStr), "%Y-%m-%d", &tmDataFim);

            // Montagem da consulta SQL para inserção na tabela 'reserva'
            std::string query = "INSERT INTO reserva (data_inicio, data_fim, quarto_id, usuario_cliente_id) VALUES ("
                                + txn.quote(dataInicioStr) + ", "
                                + txn.quote(dataFimStr) + ", "
                                + txn.quote(std::to_string(reserva.getQuarto().getId())) + ", "
                                + txn.quote(std::to_string(reserva.getUsuario().getId())) + ")";

           txn.exec(query);             

           txn.commit();
        } else {
            throw std::runtime_error("Erro ao conectar ao banco de dados.");
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        throw std::runtime_error(e.what());
    }
}