#include "Hotel.hpp"
#include <regex>

Hotel::Hotel(){}

Hotel::Hotel(const std::string &nome, const std::string &telefone_contato, const std::string &cnpj, const std::string &endereco)
    : nome(nome), telefone_contato(telefone_contato), cnpj(cnpj), endereco(endereco) {
    validarCNPJ();
}

Hotel::Hotel(int id, const std::string &nome, const std::string &telefone_contato, const std::string &cnpj, const std::string &endereco)
: id(id), nome(nome), telefone_contato(telefone_contato), cnpj(cnpj), endereco(endereco) {

}

void Hotel::validarCNPJ() {
    std::regex regex_cnpj(R"(\d{2}\.\d{3}\.\d{3}/\d{4}-\d{2})");

    if (!std::regex_match(cnpj, regex_cnpj)) {
        throw CNPJInvalidoException();
    }
}

void Hotel::setNome(const std::string &nome) {
    this->nome = nome;
}

void Hotel::setTelefoneContato(const std::string &telefone_contato) {
    this->telefone_contato = telefone_contato;
}

void Hotel::setCnpj(const std::string &cnpj) {
    this->cnpj = cnpj;
    validarCNPJ();
}

void Hotel::setEndereco(const std::string &endereco) {
    this->endereco = endereco;
}

int Hotel::getId() const {
    return id;
}

std::string Hotel::getNome() const {
    return nome;
}

std::string Hotel::getTelefoneContato() const {
    return telefone_contato;
}

std::string Hotel::getCnpj() const {
    return cnpj;
}

std::string Hotel::getEndereco() const {
    return endereco;
}