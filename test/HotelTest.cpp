#include <doctest/doctest.h>
#include "../Hotel.hpp"

TEST_CASE("Testes de configuração e obtenção dos dados do hotel") {
    Hotel hotel;

    SUBCASE("Configuração e obtenção do nome") {
        hotel.setNome("Hotel C");
        CHECK(hotel.getNome() == "Hotel C");
    }

    SUBCASE("Configuração e obtenção do telefone de contato") {
        hotel.setTelefoneContato("111111111");
        CHECK(hotel.getTelefoneContato() == "111111111");
    }

    SUBCASE("Configuração e obtenção do CNPJ") {
        hotel.setCnpj("12.345.678/0001-90");
        CHECK(hotel.getCnpj() == "12.345.678/0001-90");
    }

    SUBCASE("Configuração e obtenção do endereço") {
        hotel.setEndereco("Endereco C");
        CHECK(hotel.getEndereco() == "Endereco C");
    }
}

TEST_CASE("Testes de validação de CNPJ") {
    SUBCASE("CNPJ válido deve passar na validação") {
        CHECK_NOTHROW(Hotel("Hotel A", "123456789", "12.345.678/0001-90", "Endereco A"));
    }

    SUBCASE("CNPJ inválido deve lançar exceção CNPJInvalidoException") {
        CHECK_THROWS_AS(Hotel("Hotel B", "987654321", "12345678901234", "Endereco B"), CNPJInvalidoException);
    }
}