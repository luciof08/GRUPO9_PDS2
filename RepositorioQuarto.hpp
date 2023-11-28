#ifndef REPOSITORIOQUARTO_HPP
#define REPOSITORIOQUARTO_HPP

#include <string>
#include <vector>
#include <pqxx/pqxx>

#include "Quarto.hpp"
#include "ConexaoBancoDeDados.hpp"

class RepositorioQuarto {

private:
       std::unique_ptr<ConexaoBancoDeDados> conexao;

public:
    RepositorioQuarto();
    bool existeQuarto(std::string idQuarto);
    std::vector<Quarto> listarQuartos(std::string idHotel);
};

#endif // REPOSITORIOQUARTO_HPP