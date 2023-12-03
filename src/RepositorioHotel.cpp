#include "../include/RepositorioHotel.hpp"
#include <pqxx/pqxx>

RepositorioHotel::RepositorioHotel() {
    conexao = std::make_unique<ConexaoBancoDeDados>();
}

std::vector<Hotel> RepositorioHotel::listarHoteis() {
    std::vector<Hotel> hoteis;

    try {
            pqxx::work txn(conexao->getConnection());
            pqxx::result result = txn.exec("SELECT id, nome, telefone_contato, cnpj, endereco, valor_diaria FROM hotel");

            // Itere pelos resultados e crie objetos Hotel
            for (const auto &row : result) {
                int id = row["id"].as<int>();
                std::string nome = row["nome"].as<std::string>();
                std::string telefone_contato = row["telefone_contato"].as<std::string>();
                std::string cnpj = row["cnpj"].as<std::string>();
                std::string endereco = row["endereco"].as<std::string>();
                double valorDiaria = row["valor_diaria"].as<double>();

                // Crie objetos Hotel e adicione à lista
                Hotel hotel(id, nome, telefone_contato, cnpj, endereco, valorDiaria);
                hoteis.push_back(hotel);
            }

            txn.commit();

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        throw std::runtime_error(e.what());
    }

    return hoteis;
}