#ifndef FORMADEPAGAMENTO_HPP
#define FORMADEPAGAMENTO_HPP

#include <string>

enum class FormaDePagamento {
    BOLETO = 1,
    CARTAO_DE_CREDITO = 2,
    PIX = 3,
    CARTAO_DE_DEBITO = 4
};

class FormaDePagamentoInvalida : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Forma de pagamento inválida";
    }
};

#endif // FORMADEPAGAMENTO_HPP