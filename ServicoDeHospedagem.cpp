#include "ServicoDeHospedagem.hpp"

void ServicoDeHospedagem::cadastrarUsuario() {
    std::string nome, email, cpf, senha;

    std::cout << "Digite o nome: ";
    std::getline(std::cin, nome);

    std::cout << "Digite o email: ";
    std::getline(std::cin, email);

    std::cout << "Digite o CPF: ";
    std::getline(std::cin, cpf);

    std::cout << "Digite a senha: ";
    std::getline(std::cin, senha);

    UsuarioCliente usuario(nome, email, cpf, senha);
    usuario.cadastrar();
}

std::unique_ptr<UsuarioCliente> ServicoDeHospedagem::logarUsuario() {
    std::string login_email, login_senha;

    std::cout << "\nLogin" << std::endl;
    std::cout << "Digite o email: ";
    std::getline(std::cin, login_email);

    std::cout << "Digite a senha: ";
    std::getline(std::cin, login_senha);

    UsuarioCliente usuario(login_email, login_senha);
    std::unique_ptr<UsuarioCliente> usuarioLogado = usuario.fazer_login();
    if (usuarioLogado != nullptr) {
        std::cout << "Login bem-sucedido!" << std::endl;
    } else {
        std::cout << "Login falhou. Verifique suas credenciais." << std::endl;
    }
    return usuarioLogado;
}
