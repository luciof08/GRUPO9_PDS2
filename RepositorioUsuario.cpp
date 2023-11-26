#include "RepositorioUsuario.hpp"
#include "UsuarioCliente.hpp"
#include <iostream>
#include <pqxx/pqxx>

void RepositorioUsuario::cadastrar(const UsuarioCliente &usuario) {
    try {
        pqxx::connection conn("dbname=" + conexao.getDBName() + " user=" + conexao.getUser() + " password=" + conexao.getPassword() + " host=" + conexao.getHost());

        if (conn.is_open()) {
            pqxx::work txn(conn);

            std::string sql = "INSERT INTO usuario_cliente (nome, email, cpf, senha) VALUES ('" + usuario.getNome() + "', '" + usuario.getEmail() + "', '" + usuario.getCPF() + "', '" + usuario.getSenha() + "')";
            txn.exec(sql);
            txn.commit();

            std::cout << "Usuário cadastrado com sucesso!" << std::endl;
        } else {
            std::cerr << "Falha ao conectar ao banco de dados." << std::endl;
        }

        conn.disconnect();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

std::unique_ptr<UsuarioCliente> RepositorioUsuario::fazer_login(const UsuarioCliente &usuario) {
     try {
        pqxx::connection conn("dbname=" + conexao.getDBName() + " user=" + conexao.getUser() + " password=" + conexao.getPassword() + " host=" + conexao.getHost());

        if (conn.is_open()) {
            pqxx::work txn(conn);

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
        } else {
            std::cerr << "Falha ao conectar ao banco de dados." << std::endl;
        }

        conn.disconnect();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return nullptr; // Retorna um ponteiro nulo se o login falhar
}

bool RepositorioUsuario::verificarExistenciaUsuario(const UsuarioCliente &usuario) {
    bool usuarioExiste = false;

    try {
        pqxx::connection conn("dbname=" + conexao.getDBName() + " user=" + conexao.getUser() + " password=" + conexao.getPassword() + " host=" + conexao.getHost());

        if (conn.is_open()) {
            pqxx::work txn(conn);

            pqxx::result result = txn.exec("SELECT * FROM usuario_cliente WHERE cpf = '" + usuario.getCPF() + "'");

            if (!result.empty()) {
                usuarioExiste = true;
            }

            txn.commit();
        } else {
            std::cerr << "Falha ao conectar ao banco de dados." << std::endl;
        }

        conn.disconnect();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return usuarioExiste;
}