#include <doctest/doctest.h>
#include "../include/UsuarioCliente.hpp"

// Observação: Esses testes que precisam de acesso ao banco de dados,
// se tornam testes de integração.
// O teste de cadastro de usuário só irá passar se o usuário não existir inicialmente.
TEST_CASE("Testes de cadastro de usuário") {
    
    // Limpeza do estado do sistema (se necessário) antes de cada teste.
    
    SUBCASE("Cadastro de usuário não existente deve ser bem-sucedido") {
        UsuarioCliente usuario1("Nome", "email@teste.com", "123.456.789-10", "senha");
        CHECK_NOTHROW(usuario1.cadastrar());
    }

    SUBCASE("Cadastro de usuário já existente deve lançar exceção UsuarioJaCadastradoException") {
        UsuarioCliente usuario2("Nome", "email@teste.com", "123.456.789-10", "senha");
        CHECK_THROWS_AS(usuario2.cadastrar(), UsuarioJaCadastradoException);
    }
}

TEST_CASE("Testes de login de usuário") {
    
    // Limpeza do estado do sistema (se necessário) antes de cada teste.
    
    SUBCASE("Login com credenciais válidas deve ser bem-sucedido") {
        UsuarioCliente usuario("email@teste.com", "senha");
        auto usuario_logado = usuario.fazer_login();
        CHECK(usuario_logado != nullptr); // Verifica se o login foi bem-sucedido
    }

    SUBCASE("Login com senha incorreta deve falhar") {
        UsuarioCliente usuario("email@teste.com", "senha_incorreta");
        auto usuario_logado = usuario.fazer_login();
        CHECK(usuario_logado == nullptr); // Verifica se o login falhou
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