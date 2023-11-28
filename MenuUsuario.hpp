#ifndef MENUUSUARIO_HPP
#define MENUUSUARIO_HPP

#include <iostream>
#include <string>

class MenuUsuario {
public:
    static void mostrar_opcao_encerrar();
    static void mostrar_menu_inicial();
    static std::string escolher_opcao();
    static std::string escolher_opcao_str();
    static void mostrar_menu_usuario_logado();
};

#endif /* MENUUSUARIO_HPP */