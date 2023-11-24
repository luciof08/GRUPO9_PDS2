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

/// @brief Classe que representa os hotéis.
class Hotel {
private:
    int id;
    std::string nome;
    std::string telefone_contato;
    std::string cnpj;
    std::string endereco;

    /// @brief  Valida o cnpj do hotel
    /// @param cpf 
    void validarCNPJ();

public:

    Hotel();

    /// @brief Construtor para preencher todos os dados do hotel.
    /// @param nome 
    /// @param telefone_contato 
    /// @param cnpj 
    /// @param endereco 
    Hotel(const std::string &nome, const std::string &telefone_contato, const std::string &cnpj, const std::string &endereco);

    Hotel(int id, const std::string &nome, const std::string &telefone_contato, const std::string &cnpj, const std::string &endereco);
    
    /// @brief Define o nome do hotel
    /// @param nome 
    void setNome(const std::string &nome);

    /// @brief Define o telefone de contato do hotel
    /// @param telefone_contato 
    void setTelefoneContato(const std::string &telefone_contato);

    /// @brief Define o cnpj do hotel
    /// @param cnpj 
    void setCnpj(const std::string &cnpj);

    /// @brief Define o endereço do hotel
    /// @param endereco
    void setEndereco(const std::string &endereco);

    int getId() const;
    std::string getNome() const;
    std::string getTelefoneContato() const;
    std::string getCnpj() const;
    std::string getEndereco() const;

};

#endif // HOTEL_HPP