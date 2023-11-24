#ifndef CONEXAOBANCODEDADOS_HPP
#define CONEXAOBANCODEDADOS_HPP

#include <string>

/// @brief Classe que representa dos dados de conexão com o banco de dados
class ConexaoBancoDeDados {
private:
    std::string dbname;
    std::string user;
    std::string password;
    std::string host;

public:

    ConexaoBancoDeDados();

    /// @brief Obtém o nome do banco de dados.
    /// @return Nome do banco de dados
    std::string getDBName() const;
    /// @brief Obtém o nome do usuário do banco de dados.
    /// @return Nome do usuário do banco de dados
    std::string getUser() const;
    /// @brief Obtém a senha do usuário do banco de dados.
    /// @return Senha do usuário do banco de dados
    std::string getPassword() const;
    /// @brief Obtém o host do banco de dados.
    /// @return Host do banco de dados
    std::string getHost() const;
};

#endif // CONEXAOBANCODEDADOS_HPP