#include "../include/MenuUsuario.hpp"
#include "../include/EntradaUtil.hpp"

void MenuUsuario::mostrar_titulo_sistema() {
    std::string title = "SISTEMA DE RESERVA DE HOSPEDAGEM";
    int width = title.length() + 4; // Considerando duas barras para cada lado do título
    std::cout << std::setw(width) << std::setfill('*') << "" << std::endl;
    std::cout << "* " << std::setw(width - 3) << std::left << title << " *" << std::endl;
    std::cout << std::setw(width) << std::setfill('*') << "" << std::endl;
}

void MenuUsuario::mostrar_opcao_encerrar() {
    std::cout << "0 - Encerrar" << std::endl;
}

void MenuUsuario::mostrar_menu_inicial() {
    std::cout << "\nEscolha uma opção:" << std::endl;
    std::cout << "1 - Cadastro" << std::endl;
    std::cout << "2 - Login" << std::endl;
}

std::string MenuUsuario::escolher_opcao() {
    std::string opcao;
    std::getline(std::cin, opcao);
    EntradaUtil::removerEspacosInicioFim(opcao);
    if(!EntradaUtil::contemInteiro(opcao)) {
        throw EntradaInvalidaException();
    }
    return opcao;
}

std::string MenuUsuario::escolher_opcao_str() {
    std::string opcao;
    std::getline(std::cin, opcao);
    EntradaUtil::removerEspacosInicioFim(opcao);
    return opcao;
}

void MenuUsuario::mostrar_menu_usuario_logado() {
    std::cout << "\nEscolha uma opção:" << std::endl;
    std::cout << "1 - Listar Hoteis" << std::endl;
    std::cout << "2 - Reservas Realizadas" << std::endl;
    std::cout << "3 - Reservar Quarto" << std::endl;
}