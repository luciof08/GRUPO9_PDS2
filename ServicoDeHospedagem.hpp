#ifndef SERVICODEHOSPEDAGEM_HPP
#define SERVICODEHOSPEDAGEM_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "UsuarioCliente.hpp"
#include "RepositorioHotel.hpp"
#include "RepositorioReserva.hpp"
#include "RepositorioQuarto.hpp"
#include "MenuUsuario.hpp"
#include "EntradaUtil.hpp"

/// @brief Exceção para representar a inexistência de um hotel ou de quartos cadastrados para ele.
class HotelNaoExisteOuNaoPossuiQuartoCadastradoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "O ID do hotel informado ou não existe ou não possui quartos cadastrados!";
    }
};

/// @brief Exceção para representar a tentativa de recuperar um quarto não cadastrado.
class QuartoNaoCadastradoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "O ID do quarto informado não existe!";
    }
};

/// @brief Exceção para preenchimento de data em formato inválido.
class DataInvalidaException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Formato de data inválido!";
    }
};

/// @brief Classe que controla o fluxo de processo da reserva da hospedagem.
class ServicoDeHospedagem {

private:
    RepositorioReserva repositorioReserva;
    RepositorioQuarto repositorioQuarto;

    /// @brief Para exibir os quartos para determinado hotel
    void exibeQuartos();
    /// @brief Para o usuário escolher o id do quarto a ser colocado na reserva
    /// @return string com o id do quarto informado pelo usuário
    std::string escolherQuarto();

public:
    /// @brief realiza o fluxo de cadastramento de novo usuário no sistema
    void cadastrarUsuario();
    /// @brief Autentica o usuário no sistema
    /// @return referência para o usuário que efetuou o login
    std::unique_ptr<UsuarioCliente> logarUsuario();
    /// @brief Exibiçaõ dos hotéis existentes
    void listarHoteis();
    /// @brief Exibição das reservas de determinado usuário
    /// @param usuarioLogado usuário a que as reservas se referem
    void listarReservas(const std::unique_ptr<UsuarioCliente>& usuarioLogado);
    /// @brief Exibição dos quartos de determinado hotel
    /// @param idHotel ID do hotel
    void listarQuartos(std::string idHotel);
    /// @brief Exibição das reservas para determinado quarto
    /// @param idQuarto quarto das reservas
    void listarReservasDoQuarto(std::string idQuarto);
    /// @brief Realiza o fluxo de preenchimento da reserva 
    /// @param usuarioLogado usuário associado a reserva
    void reservarQuarto(const std::unique_ptr<UsuarioCliente>& usuarioLogado);
};

#endif /* SERVICODEHOSPEDAGEM_HPP */