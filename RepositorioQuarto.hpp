#ifndef REPOSITORIOQUARTO_HPP
#define REPOSITORIOQUARTO_HPP

#include <string>
#include <vector>
#include <pqxx/pqxx>

#include "Quarto.hpp"
#include "ConexaoBancoDeDados.hpp"

class RepositorioQuarto {
private:
    ConexaoBancoDeDados conexao;
public:
    std::vector<Quarto> listarQuartos(std::string idHotel);
};

#endif // REPOSITORIOQUARTO_HPP