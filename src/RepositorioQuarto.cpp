#include <iostream>

#include "../include/RepositorioQuarto.hpp"

RepositorioQuarto::RepositorioQuarto() {
    conexao = std::make_unique<ConexaoBancoDeDados>();
}

std::vector<Quarto> RepositorioQuarto::listarQuartos(std::string idHotel) {
    std::vector<Quarto> quartos;

    try {
        pqxx::work txn(conexao->getConnection());
        
        size_t pos; 
        int value = std::stoi(idHotel, &pos);

        std::string query = "SELECT q.id, q.numero, q.localizacao, h.cnpj \
            FROM quarto q \
            INNER JOIN hotel h ON q.hotel_id = h.id \
            WHERE h.id = " + txn.quote(value);
        
        pqxx::result result = txn.exec(query);

        for (const auto& row : result) {
            int id = row["id"].as<int>();
            int numero = row["numero"].as<int>();
            std::string cnpj = row["cnpj"].as<std::string>();
            std::string localizacao = row["localizacao"].as<std::string>();

            Hotel hotel("","",cnpj,"");

            Quarto quarto(id, numero, localizacao, hotel);
            quartos.push_back(quarto);
        }

        txn.commit();

    } catch (const std::exception& e) {
         std::cerr << "Erro: " << e.what() << std::endl;
        throw std::runtime_error(e.what());
    }

    return quartos;
}

bool RepositorioQuarto::existeQuarto(std::string idQuarto) {
    try {
        pqxx::work txn(conexao->getConnection());
        std::string query = "SELECT COUNT(*) FROM quarto WHERE id = " + txn.quote(idQuarto);
        pqxx::result result = txn.exec(query);

        int count = result[0][0].as<int>();
        txn.commit();

        return (count > 0);
    } catch (const std::exception& e) {
         std::cerr << "Erro: " << e.what() << std::endl;
        throw std::runtime_error(e.what());
    }
}

Hotel RepositorioQuarto::buscarHotel(const std::string& idQuarto) {
    try {
        pqxx::work txn(conexao->getConnection());
        pqxx::result result = txn.exec_params(
            "SELECT h.id, h.nome, h.telefone_contato, h.cnpj, h.endereco, h.valor_diaria "
            "FROM hotel h "
            "INNER JOIN quarto q ON h.id = q.hotel_id "
            "WHERE q.id = $1", idQuarto);

        // Verifica se há resultados na consulta
        if (result.size() > 0) {
            // Preenchendo os dados do hotel a partir do resultado da consulta
            int id = result[0][0].as<int>();
            std::string nome = result[0][1].as<std::string>();
            std::string telefone = result[0][2].as<std::string>();
            std::string cnpj = result[0][3].as<std::string>();
            std::string endereco = result[0][4].as<std::string>();
            double valorDiaria = result[0][5].as<double>();

            // Retorna um objeto Hotel com os dados obtidos do banco de dados
            return Hotel(id, nome, telefone, cnpj, endereco, valorDiaria);
        } else {
            // Caso não encontre o hotel, retorna um objeto Hotel vazio
            return Hotel();
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        throw std::runtime_error(e.what());
    }
}
