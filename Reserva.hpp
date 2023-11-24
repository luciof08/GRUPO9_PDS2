#ifndef RESERVA_HPP
#define RESERVA_HPP

#include "Quarto.hpp" 
#include "UsuarioCliente.hpp" 
#include <chrono>
#include <stdexcept>

class DataInicioMaiorOuIgualDataFimException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erro: A data de início deve ser anterior à data de término da reserva.";
    }
};

class Reserva {
private:
    int id;
    Quarto quarto;
    std::chrono::time_point<std::chrono::system_clock> dataInicio;
    std::chrono::time_point<std::chrono::system_clock> dataFim;
    UsuarioCliente usuario;

    void validarDataInicioMenorQueDataFim();

public:
    // Construtor
    Reserva(int id, const Quarto& quarto, const std::chrono::time_point<std::chrono::system_clock>& dataInicio,
            const std::chrono::time_point<std::chrono::system_clock>& dataFim, const UsuarioCliente& usuario);
    Reserva(const Quarto& quarto, const std::chrono::time_point<std::chrono::system_clock>& dataInicio,
            const std::chrono::time_point<std::chrono::system_clock>& dataFim, const UsuarioCliente& usuario);        

    // Getters
    int getId() const;
    Quarto getQuarto() const;
    std::chrono::time_point<std::chrono::system_clock> getDataInicio() const;
    std::chrono::time_point<std::chrono::system_clock> getDataFim() const;
    UsuarioCliente getUsuario() const;

};

#endif /* RESERVA_HPP */