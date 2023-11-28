#include "UsuarioCliente.hpp"
#include "RepositorioUsuario.hpp"
#include <iostream>
#include <regex>

UsuarioCliente::UsuarioCliente(
    const int id,
    const std::string &nome, 
    const std::string &email, 
    const std::string &cpf, 
    const std::string &senha) {
    setId(id);
    setNome(nome);
    setEmail(email);
    setCPF(cpf);
    setSenha(senha);
}

UsuarioCliente::UsuarioCliente(
    const std::string &nome, 
    const std::string &email, 
    const std::string &cpf, 
    const std::string &senha) {
    setNome(nome);
    setEmail(email);
    setCPF(cpf);
    setSenha(senha);
}

UsuarioCliente::UsuarioCliente(const std::string &email, const std::string &senha) {
    setEmail(email);
    setSenha(senha);
}

void UsuarioCliente::setId(const int id) {
    this->id = id;
}

void UsuarioCliente::setNome(const std::string &nome) {
    this->nome = nome;
}

void UsuarioCliente::setEmail(const std::string &email) {
    this->validarEmail(email);
    this->email = email;
}

void UsuarioCliente::setCPF(const std::string &cpf) {
    this->validarCPF(cpf);
    this->cpf = cpf;
}

void UsuarioCliente::setSenha(const std::string &senha) {
    this->senha = senha;
}

int UsuarioCliente::getId() const {
    return id;
}

std::string UsuarioCliente::getNome() const {
    return nome;
}

std::string UsuarioCliente::getEmail() const {
    return email;
}

std::string UsuarioCliente::getCPF() const {
    return cpf;
}

std::string UsuarioCliente::getSenha() const {
    return senha;
}


void UsuarioCliente::validarCPF(const std::string &cpf) {
    std::regex regex_cpf(R"(\d{3}\.\d{3}\.\d{3}-\d{2})");

    if (!std::regex_match(cpf, regex_cpf)) {
        throw CPFInvalidoException();
    }
}    

void UsuarioCliente::validarEmail(const std::string &email) {
    std::regex regex_email(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    if(!std::regex_match(email, regex_email)) {
        throw EmailInvalidoException();
    }
}

void UsuarioCliente::cadastrar() {
    RepositorioUsuario repositorio;
    if(repositorio.verificarExistenciaUsuario(*this)) {
        throw UsuarioJaCadastradoException();
    }
    repositorio.cadastrar(*this); 
    std::cout << std::endl;
    std::cout << "Usuário cadastrado com sucesso!" << std::endl;
    std::cout << std::endl;
}

std::unique_ptr<UsuarioCliente> UsuarioCliente::fazer_login() {
    RepositorioUsuario repositorio;
    return repositorio.fazer_login(*this);    
}