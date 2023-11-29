#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "UsuarioCliente.hpp"
#include "Hotel.hpp"

// Observação: Esses testes que precisam de acesso ao banco de dados,
// se tornam testes de integração.
// O teste de cadastro de usuário só irá passar se o usuário não existir inicialmente.
TEST_CASE("Testes de cadastro de usuário") {
    
    // Limpeza do estado do sistema (se necessário) antes de cada teste
    // Aqui você pode redefinir ou limpar o banco de dados, se aplicável
    
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
    
    // Limpeza do estado do sistema (se necessário) antes de cada teste
    // Aqui você pode redefinir ou limpar o banco de dados, se aplicável

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

TEST_CASE("Testes de validação de CNPJ") {
    SUBCASE("CNPJ válido deve passar na validação") {
        CHECK_NOTHROW(Hotel("Hotel A", "123456789", "12.345.678/0001-90", "Endereco A"));
    }

    SUBCASE("CNPJ inválido deve lançar exceção CNPJInvalidoException") {
        CHECK_THROWS_AS(Hotel("Hotel B", "987654321", "12345678901234", "Endereco B"), CNPJInvalidoException);
    }
}

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