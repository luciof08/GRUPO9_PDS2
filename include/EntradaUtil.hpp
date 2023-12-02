#ifndef ENTRADAUTIL_HPP
#define ENTRADAUTIL_HPP

#include <string>
#include <termios.h>
#include <unistd.h>
#include <iostream>

/// @brief Exceção que representa uma entrada inválida informada pelo usuário.
class EntradaInvalidaException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Formato inválido para a entrada!";
    }
};

/// @brief Classe utilitária para sanitizar as entradas de teclado do usuário
class EntradaUtil {
public:
    /// @brief remove os espaços em branco do início e fim do texto.
    /// @param str referência para a string a ser tratada 
    static void removerEspacosInicioFim(std::string& str);
    /// @brief Retorna um bool indicando se a referência da string passada é um valor inteiro.
    /// @param str referência para a string a ser tratada
    /// @return bool indicando se o valor é inteiro ou não.
    static bool contemInteiro(const std::string& str);
    /// @brief Torna o texto maiúsculo
    /// @param str referência da string informada
    static void tornarCaixaAlta(std::string& str);
    /// @brief Realiza a leitura do campo de senha
    /// @return senha lida
    static std::string lerSenha();
};

#endif // ENTRADAUTIL_HPP