#include <iostream>

#include "RepositorioQuarto.hpp"

std::vector<Quarto> RepositorioQuarto::listarQuartos(std::string idHotel) {
    std::vector<Quarto> quartos;

    try {
        pqxx::connection conn("dbname=" + conexao.getDBName() + " user=" + conexao.getUser() + " password=" + conexao.getPassword() + " host=" + conexao.getHost());
        if (conn.is_open()) {
            pqxx::work txn(conn);
            
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

         } else {
            throw std::runtime_error("Erro ao conectar ao banco de dados.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao listar quartos: " << e.what() << std::endl;
    }

    return quartos;
}