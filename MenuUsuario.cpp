#include "MenuUsuario.hpp"

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
    return opcao;
}

void MenuUsuario::mostrar_menu_usuario_logado() {
    std::cout << "\nEscolha uma opção:" << std::endl;
    std::cout << "1 - Listar Hoteis" << std::endl;
    std::cout << "2 - Reservas Realizadas" << std::endl;
    std::cout << "3 - Reservar Quarto" << std::endl;
}