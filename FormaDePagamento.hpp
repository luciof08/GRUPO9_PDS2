#ifndef FORMADEPAGAMENTO_HPP
#define FORMADEPAGAMENTO_HPP

#include <string>

/// @brief Enumeração que representa as formas de pagamento da reserva.
enum class FormaDePagamento {
    BOLETO = 1,
    CARTAO_DE_CREDITO = 2,
    PIX = 3,
    CARTAO_DE_DEBITO = 4
};

/// @brief Exceção que representa uma forma de pagamento inválida informada pelo usuário.
class FormaDePagamentoInvalida : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Forma de pagamento inválida";
    }
};

#endif // FORMADEPAGAMENTO_HPP