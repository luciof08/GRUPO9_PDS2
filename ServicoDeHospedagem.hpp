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

class ServicoDeHospedagem {

private:
    RepositorioReserva repositorioReserva;

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