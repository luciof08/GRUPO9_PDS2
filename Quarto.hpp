#ifndef QUARTO_HPP
#define QUARTO_HPP

#include "Hotel.hpp"

/// @brief Classe que representa um quarto de hotel para reserva.
class Quarto {
private:
    int id;
    int numero;
    std::string localizacao;
    Hotel hotel;

public:

    /// @brief Construtor padrão.
    Quarto();

    // Construtor para um cenário de uso para consulta com apenas o ID.
    Quarto(int id);

    /// @brief Construtor da classe quando usado para consulta a entidade.
    /// @param id Identificador do quarto
    /// @param numero Número do quarto
    /// @param hotel hotel ao qual o quarto pertence
    Quarto(int id, int numero, Hotel& hotel);

    /// @brief /// @brief Construtor da classe completo quando usado para consulta a entidade.
    /// @param id Identificador do quarto
    /// @param numero Número do quarto
    /// @param localizacao Localização do quarto dentro do hotel
    /// @param hotel hotel ao qual o quarto pertence
    Quarto(int id, int numero, std::string localizacao, const Hotel& hotel);

    /// @brief Recupera o ID do quarto. 
    /// @return int representando o id
    int getId() const;
    /// @brief Recupera o número do quarto
    /// @return int representando o id
    int getNumero() const;
    /// @brief Recupera a localização do quarto dentro do hotel
    /// @return string com a descrição da localização
    std::string getLocalizacao() const;
    /// @brief Recupera o hotel ao qual o quarto está associado
    /// @return o hotel do quarto
    Hotel getHotel() const;

};

#endif /* QUARTO_HPP */