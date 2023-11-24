#ifndef USUARIOCLIENTE_HPP
#define USUARIOCLIENTE_HPP

#include <stdexcept>
#include <string>
#include <memory>

/// @brief Classe que representa uma exceção da validação de email.
class EmailInvalidoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Email inválido.";
    }
};

/// @brief Classe que representa uma exceção da validação de cpf.
class CPFInvalidoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "CPF inválido.";
    }
};

class UsuarioJaCadastradoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Usuário já cadastrado.";
    }
};


/// @brief Classe que representa os usuários do sistema.
class UsuarioCliente {
private:
    int id;
    std::string nome;
    std::string email;
    std::string cpf;
    std::string senha;

    /// @brief  Valida o cpf do usuário
    /// @param cpf 
    void validarCPF(const std::string &cpf);
    /// @brief Valida o email do usuário
    /// @param email 
    void validarEmail(const std::string &email);

public:

    UsuarioCliente(const int id, const std::string &nome, const std::string &email, const std::string &cpf, const std::string &senha);

    /// @brief Construtor para preencher os dados do usuário sem o id.
    /// @param nome 
    /// @param email 
    /// @param cpf 
    /// @param senha 
    UsuarioCliente(const std::string &nome, const std::string &email, const std::string &cpf, const std::string &senha);
    
    /// @brief Construtor apenas para a realização do login, onde é necessário apenas email e senha.
    /// @param email 
    /// @param senha 
    UsuarioCliente(const std::string &email, const std::string &senha);


    /// @brief Define o id do usuário
    /// @param id 
    void setId(const int id);
    /// @brief Define o nome do usuário
    /// @param nome 
    void setNome(const std::string &nome);
    /// @brief Define o email do usuário
    /// @param email 
    void setEmail(const std::string &email);
    /// @brief Define o cpf do usuário
    /// @param cpf 
    void setCPF(const std::string &cpf);
    /// @brief  Define a senha do usuário
    /// @param senha 
    void setSenha(const std::string &senha);

    int getId() const;
    std::string getNome() const;
    std::string getEmail() const;
    std::string getCPF() const;
    std::string getSenha() const;

    /// @brief Realiza o login do usuário no sistema.
    /// @return Retorna um ponteiro para UsuarioCliente logado ou null.
    std::unique_ptr<UsuarioCliente> fazer_login();
    /// @brief Cadastra o usuário no sistema.
    void cadastrar();
};

#endif // USUARIOCLIENTE_HPP