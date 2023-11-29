#include <doctest/doctest.h>
#include "../include/EntradaUtil.hpp"

TEST_CASE("Testes da classe EntradaUtil") {
    SUBCASE("Teste de remoção de espaços em branco do início e fim da string") {
        std::string texto = "   Olá, mundo!   ";
        EntradaUtil::removerEspacosInicioFim(texto);
        CHECK_EQ(texto, "Olá, mundo!");
    }

    SUBCASE("Teste de detecção de valor inteiro na string") {
        std::string texto1 = "12345";
        std::string texto2 = "Olá, mundo!";
        CHECK(EntradaUtil::contemInteiro(texto1) == true);
        CHECK(EntradaUtil::contemInteiro(texto2) == false);
    }

    SUBCASE("Teste de conversão para caixa alta") {
        std::string texto = "Ola, mundo";
        EntradaUtil::tornarCaixaAlta(texto);
        CHECK_EQ(texto, "OLA, MUNDO");
    }
}