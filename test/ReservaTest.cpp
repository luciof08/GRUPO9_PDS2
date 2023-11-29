#include "doctest/doctest.h"
#include "../Reserva.hpp"
#include <chrono>

TEST_CASE("Testes da classe Reserva") {
    // Criação de instâncias necessárias para testes
    UsuarioCliente usuario("Nome", "email@teste.com", "123.456.789-10", "senha");
    Hotel hotel("Hotel 5 estrelas", "00 00000 0000", "12.345.678/0001-90", "Endereco A");
    Quarto quarto(101, 2, "Suite", hotel);
    std::chrono::time_point<std::chrono::system_clock> dataInicio = std::chrono::system_clock::now();
    std::chrono::time_point<std::chrono::system_clock> dataFim = dataInicio + std::chrono::hours(24 * 7); // Adiciona uma semana

    SUBCASE("Teste do construtor com ID já existente") {
        Reserva reserva(1, quarto, dataInicio, dataFim, usuario);

        CHECK_EQ(reserva.getId(), 1);
    }

    SUBCASE("Teste de exceções para datas inválidas") {
        // Teste para garantir que uma exceção é lançada quando a data de início é maior ou igual à data de fim
        std::chrono::time_point<std::chrono::system_clock> dataInicioInvalida = dataFim;
        CHECK_THROWS_AS(Reserva(quarto, dataInicioInvalida, dataFim, usuario), DataInicioMaiorOuIgualDataFimException);

        // Teste para garantir que uma exceção é lançada quando a data de início é menor que a data atual
        std::chrono::time_point<std::chrono::system_clock> dataInicioAntesDeAgora = dataInicio - std::chrono::hours(24 * 7); // 1 semana antes
        CHECK_THROWS_AS(Reserva(quarto, dataInicioAntesDeAgora, dataFim, usuario), DataInicioMenorQueDataAtualException);
    }
}