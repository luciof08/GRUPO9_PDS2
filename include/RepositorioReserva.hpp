#ifndef REPOSITORIORESERVA_HPP
#define REPOSITORIORESERVA_HPP

#include <vector>
#include "Reserva.hpp" 
#include "UsuarioCliente.hpp" 
#include "ConexaoBancoDeDados.hpp"
#include "FormaDePagamentoUtil.hpp"

/// @brief Classe que representa o repositório para a Reserva
class RepositorioReserva {

private:
    std::unique_ptr<ConexaoBancoDeDados> conexao;

public:

    /// @brief Construtor padrão
    RepositorioReserva();

    /// @brief Recupera os dados das reservas do usuário
    /// @param usuario que efetuou as reservas
    /// @return lista com as reservas já realizadas pelo usuário
    std::vector<Reserva> listarReservas(const std::unique_ptr<UsuarioCliente>& usuario);
    /// @brief Recupera as reservas para o quarto
    /// @param idQuarto das reservas realizadas
    /// @return lista de reservas para o quarto
    std::vector<Reserva> listarReservasDoQuarto(std::string idQuarto); 
    /// @brief Cria uma reserva
    /// @param reserva referência da reserva a ser salva    
    void incluir(const Reserva& reserva);
    /// @brief Verifica se a reserva solicitada está disponível
    /// @param reserva referência da reserva a ser consultada
    /// @return true se o período está disponível para reserva daquele quarto, false caso contrário
    bool estaDisponivel(const Reserva& reserva);
};

#endif /* REPOSITORIORESERVA_HPP */