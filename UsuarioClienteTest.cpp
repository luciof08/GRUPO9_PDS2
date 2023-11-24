#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "UsuarioCliente.hpp"

// Observação: Esses testes que precisam de acesso ao banco de dados,
// se tornam testes de integração.
// O teste de cadastro de usuário só irá passar se o usuário não existir inicialmente.
TEST_CASE("Testes de cadastro de usuário") {
    UsuarioCliente usuario("Nome", "email@teste.com", "123.456.789-10", "senha");

    SUBCASE("Cadastro de usuário não existente deve ser bem-sucedido") {
        CHECK_NOTHROW(usuario.cadastrar());
    }

    SUBCASE("Cadastro de usuário já existente deve lançar exceção UsuarioJaCadastradoException") {
        CHECK_THROWS_AS(usuario.cadastrar(), UsuarioJaCadastradoException);
    }
}

TEST_CASE("Testes de login de usuário") {
    UsuarioCliente usuario("email@teste.com", "senha");

    SUBCASE("Login com credenciais válidas deve ser bem-sucedido") {
        CHECK(usuario.fazer_login());
    }

    SUBCASE("Login com senha incorreta deve falhar") {
        usuario.setSenha("senha_incorreta");
        CHECK_FALSE(usuario.fazer_login());
    }
}

TEST_CASE("Testes de validação de CPF") {
    SUBCASE("CPF válido deve passar na validação") {
        CHECK_NOTHROW(UsuarioCliente("Nome", "email@teste.com", "123.456.789-10", "senha"));
    }

    SUBCASE("CPF inválido deve lançar exceção CPFInvalidoException") {
        CHECK_THROWS_AS(UsuarioCliente("Nome", "email@teste.com", "123.456.789", "senha"), CPFInvalidoException);
    }
}

TEST_CASE("Testes de validação de email") {
    SUBCASE("Email válido deve passar na validação") {
        CHECK_NOTHROW(UsuarioCliente("Nome", "email@teste.com", "123.456.789-10", "senha"));
    }

    SUBCASE("Email inválido deve lançar exceção EmailInvalidoException") {
        CHECK_THROWS_AS(UsuarioCliente("Nome", "email_invalido.com", "123.456.789-10", "senha"), EmailInvalidoException);
    }
}
