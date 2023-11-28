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

class HotelNaoExisteOuNaoPossuiQuartoCadastradoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "O ID do hotel informado ou não existe ou não possui quartos cadastrados!";
    }
};

class QuartoNaoCadastradoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "O ID do quarto informado não existe!";
    }
};

class DataInvalidaException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Formato de data inválido!";
    }
};

class ServicoDeHospedagem {

private:
    RepositorioReserva repositorioReserva;
    RepositorioQuarto repositorioQuarto;

    void exibeQuartos();
    std::string escolherQuarto();

public:

    void cadastrarUsuario();
    std::unique_ptr<UsuarioCliente> logarUsuario();
    void listarHoteis();
    void listarReservas(const std::unique_ptr<UsuarioCliente>& usuarioLogado);
    void listarQuartos(std::string idHotel);
    void listarReservasDoQuarto(std::string idQuarto);
    void reservarQuarto(const std::unique_ptr<UsuarioCliente>& usuarioLogado);
};

#endif /* SERVICODEHOSPEDAGEM_HPP */