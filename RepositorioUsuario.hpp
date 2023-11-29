#ifndef REPOSITORIOUSUARIO_HPP
#define REPOSITORIOUSUARIO_HPP

#include "ConexaoBancoDeDados.hpp"
#include "UsuarioCliente.hpp"

#include <memory>
#include <string>
/// @brief Classe que representa o repositório para UsuarioCliente
class RepositorioUsuario {

private:
    std::unique_ptr<ConexaoBancoDeDados> conexao;

public:

    /// @brief Construtor padrão
    RepositorioUsuario();

    /// @brief Cadastra um usuário no banco de dados.
    /// @param usuario a ser cadastrado
    void cadastrar(const UsuarioCliente &usuario);
    /// @brief Verifica se o usuário existe com as credenciais informadas.
    /// @param usuario Usuário a ser checado
    /// @return true se o usuário existe com as credenciais informadas.
    std::unique_ptr<UsuarioCliente> fazer_login(const UsuarioCliente &usuario);
    /// @brief Verifica a existência de um usuário pelo CPF.
    /// @param Usuário a ser checado 
    /// @return true para a existência de um usuário pelo CPF
    bool verificarExistenciaUsuario(const UsuarioCliente &usuario);
};

#endif // REPOSITORIOUSUARIO_HPP