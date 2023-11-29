#ifndef MENUUSUARIO_HPP
#define MENUUSUARIO_HPP

#include <iostream>
#include <string>

/// @brief Classe para exibição de menu de usuário.
class MenuUsuario {
public:
    /// @brief Exibe a opção encerrar menu.
    static void mostrar_opcao_encerrar();
    /// @brief  Exibe o menu inicial quando o usuário inicia o programa.
    static void mostrar_menu_inicial();
    /// @brief Retorna a opção digitada pelo usuário, para um valor inteiro lido. Lança EntradaInvalidaException se o valor digitado não for inteiro.
    /// @return string com a opção digitada
    static std::string escolher_opcao();
    /// @brief Retorna a opção digitada pelo usuário 
    /// @return string com a opção digitada
    static std::string escolher_opcao_str();
    /// @brief Mostra o menu do usuário para quando ele estiver logado no sistema.
    static void mostrar_menu_usuario_logado();
};

#endif /* MENUUSUARIO_HPP */