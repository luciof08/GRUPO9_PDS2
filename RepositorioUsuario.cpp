#include "RepositorioUsuario.hpp"
#include "UsuarioCliente.hpp"
#include <iostream>
#include <pqxx/pqxx>

RepositorioUsuario::RepositorioUsuario() {
    conexao = std::make_unique<ConexaoBancoDeDados>();
}

void RepositorioUsuario::cadastrar(const UsuarioCliente &usuario) {
    try {
        pqxx::work txn(conexao->getConnection());

        std::string sql = "INSERT INTO usuario_cliente (nome, email, cpf, senha) VALUES ('" + usuario.getNome() + "', '" + usuario.getEmail() + "', '" + usuario.getCPF() + "', '" + usuario.getSenha() + "')";
        txn.exec(sql);
        txn.commit();

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        throw std::runtime_error(e.what());
    }
}

std::unique_ptr<UsuarioCliente> RepositorioUsuario::fazer_login(const UsuarioCliente &usuario) {
     try {
        pqxx::work txn(conexao->getConnection());

        pqxx::result result = txn.exec("SELECT * FROM usuario_cliente WHERE email = '" + usuario.getEmail() + "'");

        if (!result.empty()) {
            std::string senha_banco = result[0]["senha"].as<std::string>();

            if (usuario.getSenha() == senha_banco) {

                // Se o login for bem-sucedido, crie um objeto UsuarioCliente com os dados encontrados
                std::unique_ptr<UsuarioCliente> usuario_encontrado = std::make_unique<UsuarioCliente>(
                    result[0]["id"].as<int>(),
                    result[0]["nome"].as<std::string>(),
                    result[0]["email"].as<std::string>(),
                    result[0]["cpf"].as<std::string>(),
                    result[0]["senha"].as<std::string>()
                    
                );
                return usuario_encontrado;
            } else {
                std::cout << "Senha incorreta." << std::endl;
            }
        } else {
            std::cout << "Usuário não encontrado." << std::endl;
        }

        txn.commit();

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        throw std::runtime_error(e.what());
    }

    return nullptr; // Retorna um ponteiro nulo se o login falhar
}

bool RepositorioUsuario::verificarExistenciaUsuario(const UsuarioCliente &usuario) {
    bool usuarioExiste = false;

    try {
        pqxx::work txn(conexao->getConnection());

        pqxx::result result = txn.exec("SELECT * FROM usuario_cliente WHERE cpf = '" + usuario.getCPF() + "'");

        if (!result.empty()) {
            usuarioExiste = true;
        }

        txn.commit();

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        throw std::runtime_error(e.what());
    }

    return usuarioExiste;
}