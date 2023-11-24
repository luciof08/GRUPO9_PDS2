#include "Reserva.hpp"
#include <iostream>

// Construtor
Reserva::Reserva(int id, const Quarto& quarto, const std::chrono::time_point<std::chrono::system_clock>& dataInicio,
        const std::chrono::time_point<std::chrono::system_clock>& dataFim, const UsuarioCliente& usuario)
    : id(id), quarto(quarto), dataInicio(dataInicio), dataFim(dataFim), usuario(usuario) {}
Reserva::Reserva(const Quarto& quarto, const std::chrono::time_point<std::chrono::system_clock>& dataInicio,
        const std::chrono::time_point<std::chrono::system_clock>& dataFim, const UsuarioCliente& usuario)
    : quarto(quarto), dataInicio(dataInicio), dataFim(dataFim), usuario(usuario) {
        validarDataInicioMenorQueDataFim();
    }

void Reserva::validarDataInicioMenorQueDataFim() {
    if (dataInicio >= dataFim) {
        throw DataInicioMaiorOuIgualDataFimException();
    }
}

// Getters
int Reserva::getId() const {
    return id;
}

Quarto Reserva::getQuarto() const {
    return quarto;
}

std::chrono::time_point<std::chrono::system_clock> Reserva::getDataInicio() const {
    return dataInicio;
}

std::chrono::time_point<std::chrono::system_clock> Reserva::getDataFim() const {
    return dataFim;
}

UsuarioCliente Reserva::getUsuario() const {
    return usuario;
}