#include "Reserva.hpp"

// Construtor
Reserva::Reserva(int id, const Quarto& quarto, const std::chrono::time_point<std::chrono::system_clock>& dataInicio,
        const std::chrono::time_point<std::chrono::system_clock>& dataFim, const UsuarioCliente& usuario)
    : id(id), quarto(quarto), dataInicio(dataInicio), dataFim(dataFim), usuario(usuario) {}
Reserva::Reserva(const Quarto& quarto, const std::chrono::time_point<std::chrono::system_clock>& dataInicio,
        const std::chrono::time_point<std::chrono::system_clock>& dataFim, const UsuarioCliente& usuario)
    : quarto(quarto), dataInicio(dataInicio), dataFim(dataFim), usuario(usuario) {}

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

// Setters
void Reserva::setId(int id) {
    this->id = id;
}

void Reserva::setQuarto(const Quarto& quarto) {
    this->quarto = quarto;
}

void Reserva::setDataInicio(const std::chrono::time_point<std::chrono::system_clock>& dataInicio) {
    this->dataInicio = dataInicio;
}

void Reserva::setDataFim(const std::chrono::time_point<std::chrono::system_clock>& dataFim) {
    this->dataFim = dataFim;
}

void Reserva::setUsuario(const UsuarioCliente& usuario) {
    this->usuario = usuario;
}