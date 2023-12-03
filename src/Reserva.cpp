#include "../include/Reserva.hpp"
#include <iostream>

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

    const std::locale oldLocale = std::cout.imbue(std::locale("pt_BR.UTF-8"));
    std::cout << "Valor da diária do hotel " << quarto.getHotel().getNome() << ": R$ " << std::fixed << std::setprecision(2) << quarto.getDiariaDoHotel() << std::endl;
    // Restaura o locale anterior
    std::cout.imbue(oldLocale);

    std::cout << "Dias calculados: " << numDias << std::endl;
    return quarto.getDiariaDoHotel() * numDias; 
}

void Reserva::setFormaDePagamento(const FormaDePagamento& formaDePagamento) {
    this->formaDePagamento = formaDePagamento;
}

FormaDePagamento Reserva::getFormaDePagamento() const {
    return formaDePagamento;
}

void Reserva::validarDataInicioMaiorOuIgualQueODiaAtual() {
    // Obtendo a data atual
    auto agora = std::chrono::system_clock::now();
    std::time_t tempoAtual = std::chrono::system_clock::to_time_t(agora);
    std::tm dataAtual = *std::localtime(&tempoAtual);

    // Convertendo dataInicio para std::tm
    std::time_t tempoInicio = std::chrono::system_clock::to_time_t(dataInicio);
    std::tm dataInicioTm = *std::localtime(&tempoInicio);

    // Comparando apenas dia, mês e ano
    if (dataInicioTm.tm_year < dataAtual.tm_year ||
        (dataInicioTm.tm_year == dataAtual.tm_year && dataInicioTm.tm_mon < dataAtual.tm_mon) ||
        (dataInicioTm.tm_year == dataAtual.tm_year && dataInicioTm.tm_mon == dataAtual.tm_mon &&
         dataInicioTm.tm_mday < dataAtual.tm_mday)) {
        throw DataInicioMenorQueDataAtualException();
    }
}