#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <stdexcept>
#include <string>

/// @brief Classe que representa uma exceção da validação de cnpj.
class CNPJInvalidoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "CNPJ inválido.";
    }
};

/// @brief Classe que representa uma exceção da validação do valor da diária.
class ValorDaDiariaInvalidaException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Valor da diária inválido.";
    }
};

/// @brief Classe que representa os hotéis.
class Hotel {
private:
    int id;
    std::string nome;
    std::string telefone_contato;
    std::string cnpj;
    std::string endereco;
    double valorDiaria;

    /// @brief  Valida o formato do cnpj informado
    void validarCNPJ();

    /// @brief Valida se o valor da diária é maior ou igual a zero
    void validarValorDiaria();

public:

    /// @brief Construtor da classe.
    Hotel();

    /// @brief Construtor para preencher todos os dados do hotel. Usado na criação.
    /// @param nome Nome do hotel
    /// @param telefone_contato Telefone de contato do hotel
    /// @param cnpj Cnpj do hotel
    /// @param endereco Endereço do hotel
    Hotel(const std::string &nome, const std::string &telefone_contato, const std::string &cnpj, const std::string &endereco);

    /// @brief Construtor para quando o hotel já existe e é consultado, pois já possui ID.
    /// @param id ID do hotel
    /// @param nome Nome do hotel
    /// @param telefone_contato Telefone de contato do hotel
    /// @param cnpj Cnpj do hotel
    /// @param endereco Endereço do hotel 
    Hotel(int id, const std::string &nome, const std::string &telefone_contato, const std::string &cnpj, const std::string &endereco, const double valorDiaria);
    
    /// @brief Define o nome do hotel
    /// @param nome Nome do hotel
    void setNome(const std::string &nome);

    /// @brief Define o telefone de contato do hotel
    /// @param telefone_contato Telefone de contato do hotel
    void setTelefoneContato(const std::string &telefone_contato);

    /// @brief Define o cnpj do hotel
    /// @param cnpj CNPJ do hotel
    void setCnpj(const std::string &cnpj);

    /// @brief Define o endereço do hotel
    /// @param endereco Endereço do hotel
    void setEndereco(const std::string &endereco);

    /// @brief Retorna o identificador do hotel
    /// @return O identificador do hotel
    int getId() const;
    /// @brief Recupera o nome do hotel
    /// @return nome do hotel
    std::string getNome() const;
    /// @brief Recupera o telefone do hotel
    /// @return telefone de contato do hotel
    std::string getTelefoneContato() const;
    /// @brief Recupera o CNPJ do hotel
    /// @return CNPJ do hotel
    std::string getCnpj() const;
    /// @brief Recupera o Endereço do hotel
    /// @return o Endereço do hotel
    std::string getEndereco() const;
    /// @brief Recupera o valor da diária
    /// @return valor da diária do hotel
    double getValorDiaria() const;

};

#endif // HOTEL_HPP