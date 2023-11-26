#include "Reserva.hpp"
#include <iostream>

const double Reserva::PRECO_DIARIA = 100.0;

// Construtor
Reserva::Reserva(int id, const Quarto& quarto, const std::chrono::time_point<std::chrono::system_clock>& dataInicio,
        const std::chrono::time_point<std::chrono::system_clock>& dataFim, const UsuarioCliente& usuario)
    : id(id), quarto(quarto), dataInicio(dataInicio), dataFim(dataFim), usuario(usuario) {}

Reserva::Reserva(const Quarto& quarto, const std::chrono::time_point<std::chrono::system_clock>& dataInicio,
        const std::chrono::time_point<std::chrono::system_clock>& dataFim, const UsuarioCliente& usuario)
    : quarto(quarto), dataInicio(dataInicio), dataFim(dataFim), usuario(usuario) {
        validarDataInicioMaiorOuIgualQueODiaAtual();
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

double Reserva::calcularPrecoFinal() const {
    std::chrono::duration<double> duracao = dataFim - dataInicio;
    int numDias = static_cast<int>(std::chrono::duration_cast<std::chrono::hours>(duracao).count() / 24); 
    std::cout << "Dias calculados: " << numDias << std::endl;
    return PRECO_DIARIA * numDias; 
}

void Reserva::setFormaDePagamento(const FormaDePagamento& formaDePagamento) {
    this->formaDePagamento = formaDePagamento;
}

FormaDePagamento Reserva::getFormaDePagamento() const {
    return formaDePagamento;
}

void Reserva::validarDataInicioMaiorOuIgualQueODiaAtual() {
    std::chrono::time_point<std::chrono::system_clock> dataAtual = std::chrono::system_clock::now();

    if (dataInicio < dataAtual) {
        throw DataInicioMenorQueDataAtualException();
    }
}