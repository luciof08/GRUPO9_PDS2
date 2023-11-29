#ifndef REPOSITORIOQUARTO_HPP
#define REPOSITORIOQUARTO_HPP

#include <string>
#include <vector>
#include <pqxx/pqxx>

#include "Quarto.hpp"
#include "ConexaoBancoDeDados.hpp"

/// @brief Classe que representa o repositório para Quarto
class RepositorioQuarto {

private:
       std::unique_ptr<ConexaoBancoDeDados> conexao;

public:
    /// @brief Construtor padrão da classe
    RepositorioQuarto();
    
    /// @brief Verifica a existência de um quarto pelo ID
    /// @param idQuarto id do quarto
    /// @return true se o id existe para um quarto, false caso contrário
    bool existeQuarto(std::string idQuarto);
    /// @brief Consulta os quartos no banco de dados pelo ID do hotel a quele pertence
    /// @param idHotel ID do Hotel do Quarto
    /// @return lista com os quartos do hotel 
    std::vector<Quarto> listarQuartos(std::string idHotel);
};

#endif // REPOSITORIOQUARTO_HPP