#include <doctest/doctest.h>
#include "../include/FormaDePagamentoUtil.hpp"

TEST_CASE("Testes da classe FormaDePagamentoUtil") {
    SUBCASE("Teste de conversão para string") {
        FormaDePagamento forma1 = FormaDePagamento::CARTAO_DE_CREDITO;
        FormaDePagamento forma2 = FormaDePagamento::BOLETO;
        FormaDePagamento forma3 = FormaDePagamento::PIX;
        FormaDePagamento forma4 = FormaDePagamento::CARTAO_DE_DEBITO;

        CHECK_EQ(FormaDePagamentoUtil::toString(forma1), "2");
        CHECK_EQ(FormaDePagamentoUtil::toString(forma2), "1");
        CHECK_EQ(FormaDePagamentoUtil::toString(forma3), "3");
        CHECK_EQ(FormaDePagamentoUtil::toString(forma4), "4");

        FormaDePagamento formaInvalida = static_cast<FormaDePagamento>(100);
        CHECK_THROWS_AS(FormaDePagamentoUtil::toString(formaInvalida), FormaDePagamentoInvalida);
    }
}