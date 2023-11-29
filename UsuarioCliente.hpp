#ifndef USUARIOCLIENTE_HPP
#define USUARIOCLIENTE_HPP

#include <stdexcept>
#include <string>
#include <memory>

/// @brief Classe que representa uma exceção da validação de email.
class EmailInvalidoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Email do usuário é inválido.";
    }
};

/// @brief Classe que representa uma exceção da validação de cpf.
class CPFInvalidoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "CPF do usuário é inválido.";
    }
};

/// @brief Classe que representa uma exceção de caso se tente cadastrar um usuário com dados de outro usuário já cadastrado.
class UsuarioJaCadastradoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Usuário já cadastrado. Verifique o email ou cpf!";
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
    /// @param cpf no formato (\d{3}\.\d{3}\.\d{3}-\d{2})
    void validarCPF(const std::string &cpf);
    /// @brief Valida o email do usuário
    /// @param email no formato 
    void validarEmail(const std::string &email);

public:

    /// @brief Construtor com id usado para recuperar a entidade da base dados.
    /// @param id Identificador do usuário
    /// @param nome Nome do usuário
    /// @param email Email do usuário
    /// @param cpf CPF do usuário
    /// @param senha Senha do usuário
    UsuarioCliente(const int id, const std::string &nome, const std::string &email, const std::string &cpf, const std::string &senha);

    /// @brief Construtor para preencher os dados do usuário sem o id.
    /// @param nome Nome do usuário
    /// @param email Email do usuário
    /// @param cpf CPF do usuário
    /// @param senha Senha do usuário 
    UsuarioCliente(const std::string &nome, const std::string &email, const std::string &cpf, const std::string &senha);
    
    /// @brief Construtor apenas para a realização do login, onde é necessário apenas email e senha.
    /// @param email Email do usuário 
    /// @param senha Senha do usuário 
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

    /// @brief Recupera o Id
    /// @return ID do usuário
    int getId() const;
    /// @brief Recupera o nome
    /// @return Nome do usuário
    std::string getNome() const;
    /// @brief Recupera o email
    /// @return Email do usuário
    std::string getEmail() const;
    /// @brief Recupera o CPF
    /// @return CPF do usuário
    std::string getCPF() const;
    /// @brief Recupera o senha
    /// @return Senha do usuário
    std::string getSenha() const;

    /// @brief Realiza o login do usuário no sistema.
    /// @details Verifica as credenciais e retorna um ponteiro para um objeto UsuarioCliente logado.
    /// @return Retorna um ponteiro para UsuarioCliente logado ou null se o login falhar.
    std::unique_ptr<UsuarioCliente> fazer_login();
    /// @brief Cadastra o usuário no sistema.
    /// @details Salva o usuário no sistema após a validação dos dados.
    void cadastrar();
};

#endif // USUARIOCLIENTE_HPP