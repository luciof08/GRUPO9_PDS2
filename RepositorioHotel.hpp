#ifndef REPOSITORIOHOTEL_HPP
#define REPOSITORIOHOTEL_HPP

#include "Hotel.hpp"
#include "ConexaoBancoDeDados.hpp"
#include <vector>
#include <iostream>

/// @brief Classe que representa o repositório para Hotel
class RepositorioHotel {

private:
    ConexaoBancoDeDados conexao;

public:
    /// @brief Consulta os hotéis do banco de dados.
    /// @return uma lista de hotéis
    std::vector<Hotel> listarHoteis();
};

#endif // REPOSITORIOHOTEL_HPP