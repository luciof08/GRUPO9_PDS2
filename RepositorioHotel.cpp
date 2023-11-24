#include "RepositorioHotel.hpp"
#include <pqxx/pqxx>

std::vector<Hotel> RepositorioHotel::listarHoteis() {
    std::vector<Hotel> hoteis;

    try {
        // Conecte ao banco de dados
        pqxx::connection conn("dbname=" + conexao.getDBName() + " user=" + conexao.getUser() + " password=" + conexao.getPassword() + " host=" + conexao.getHost());
        if (conn.is_open()) {
            // Execute a consulta SQL
            pqxx::work txn(conn);
            pqxx::result result = txn.exec("SELECT id, nome, telefone_contato, cnpj, endereco FROM hotel");

            // Itere pelos resultados e crie objetos Hotel
            for (const auto &row : result) {
                int id = row["id"].as<int>();
                std::string nome = row["nome"].as<std::string>();
                std::string telefone_contato = row["telefone_contato"].as<std::string>();
                std::string cnpj = row["cnpj"].as<std::string>();
                std::string endereco = row["endereco"].as<std::string>();

                // Crie objetos Hotel e adicione à lista
                Hotel hotel(id, nome, telefone_contato, cnpj, endereco);
                hoteis.push_back(hotel);
            }

            txn.commit();
        } else {
            throw std::runtime_error("Falha ao conectar ao banco de dados.");
        }

        conn.disconnect();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return hoteis;
}