#ifndef RESERVA_HPP
#define RESERVA_HPP

#include "Quarto.hpp" 
#include "UsuarioCliente.hpp" 
#include "FormaDePagamento.hpp"
#include <chrono>
#include <stdexcept>

/// @brief Exceção para representar a data inicial da reserva maior que a data final
class DataInicioMaiorOuIgualDataFimException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erro: A data de início deve ser anterior à data de término da reserva.";
    }
};

/// @brief Exceção para indicar que a data inicial da reserva deve ser maior ou igual que o dia atual
class DataInicioMenorQueDataAtualException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erro: A data de início deve ser igual ou maior que a data atual.";
    }
};

/// @brief Classe que representa uma reserva da hospedagem 
class Reserva {
private:
    int id;
    Quarto quarto;
    std::chrono::time_point<std::chrono::system_clock> dataInicio;
    std::chrono::time_point<std::chrono::system_clock> dataFim;
    UsuarioCliente usuario;
    static const double PRECO_DIARIA;
    FormaDePagamento formaDePagamento;

    /// @brief Validação para impedir que a data de início da reserva seja menor a data de término da reserva
    void validarDataInicioMenorQueDataFim();
    /// @brief Validação para impedir que a data de início da reserva não seja anterior ao dia atual
    void validarDataInicioMaiorOuIgualQueODiaAtual();

public:
    /// @brief Construtor com ID já existente, para apenas popular o objeto
    /// @param id Identificador da reserva
    /// @param quarto quarto da reserva
    /// @param dataInicio data de início da reserva
    /// @param dataFim data de término da reserva
    /// @param usuario usuário que realiza a reserva
    Reserva(int id, const Quarto& quarto, const std::chrono::time_point<std::chrono::system_clock>& dataInicio,
            const std::chrono::time_point<std::chrono::system_clock>& dataFim, const UsuarioCliente& usuario);
    /// @brief Construtor para criação de uma reserva, para que ela seja armazenada
    /// @param quarto quarto da reserva
    /// @param dataInicio data de início da reserva
    /// @param dataFim data de término da reserva
    /// @param usuario usuário que realiza a reserva
    Reserva(const Quarto& quarto, const std::chrono::time_point<std::chrono::system_clock>& dataInicio,
            const std::chrono::time_point<std::chrono::system_clock>& dataFim, const UsuarioCliente& usuario);        

    /// @brief retorna o ID da reserva
    /// @return int do ID da reserva
    int getId() const;
    /// @brief Recupera o quarto associado a reserva
    /// @return quarto da reserva
    Quarto getQuarto() const;
    /// @brief Recupera a data inicial da reserva
    /// @return data de início da reserva
    std::chrono::time_point<std::chrono::system_clock> getDataInicio() const;
    /// @brief Recupera a data de término da reserva
    /// @return data de término da reserva
    std::chrono::time_point<std::chrono::system_clock> getDataFim() const;
    /// @brief Obtém o usuário da reserva
    /// @return usuário da reserva
    UsuarioCliente getUsuario() const;
    /// @brief recupera a forma de pagamento da reserva
    /// @return forma de pagamento da reserva
    FormaDePagamento getFormaDePagamento() const;
    /// @brief Realiza o cálculo do preço final da reserva
    /// @return double representando o preço final da reserva calculado
    double calcularPrecoFinal() const;
    /// @brief Atualiza a forma de pagamento na reserva
    /// @param formaDePagamento da reserva
    void setFormaDePagamento(const FormaDePagamento& formaDePagamento);

};

#endif /* RESERVA_HPP */