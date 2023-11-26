#ifndef SERVICODEHOSPEDAGEM_HPP
#define SERVICODEHOSPEDAGEM_HPP

#include <iostream>
#include <string>
#include "UsuarioCliente.hpp"

class ServicoDeHospedagem {
public:
    void cadastrarUsuario();
    std::unique_ptr<UsuarioCliente> logarUsuario();
};

#endif /* SERVICODEHOSPEDAGEM_HPP */