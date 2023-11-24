#ifndef RESERVA_HPP
#define RESERVA_HPP

#include "Quarto.hpp" 
#include "UsuarioCliente.hpp" 
#include <chrono>

class Reserva {
private:
    int id;
    Quarto quarto;
    std::chrono::time_point<std::chrono::system_clock> dataInicio;
    std::chrono::time_point<std::chrono::system_clock> dataFim;
    UsuarioCliente usuario;

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

    // Setters
    void setId(int id);
    void setQuarto(const Quarto& quarto);
    void setDataInicio(const std::chrono::time_point<std::chrono::system_clock>& dataInicio);
    void setDataFim(const std::chrono::time_point<std::chrono::system_clock>& dataFim);
    void setUsuario(const UsuarioCliente& usuario);
};

#endif /* RESERVA_HPP */