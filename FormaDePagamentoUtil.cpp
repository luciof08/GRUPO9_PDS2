#include "FormaDePagamentoUtil.hpp"

std::string FormaDePagamentoUtil::toString(FormaDePagamento forma) {
    switch (forma) {
        case FormaDePagamento::BOLETO:
            return "1";
        case FormaDePagamento::CARTAO_DE_CREDITO:
            return "2";
        case FormaDePagamento::PIX:
            return "3";
        case FormaDePagamento::CARTAO_DE_DEBITO:
            return "4";
        default:
             throw FormaDePagamentoInvalida();
    }
}