#ifndef ENTRADAUTIL_HPP
#define ENTRADAUTIL_HPP

#include <string>

class EntradaInvalidaException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Formato inválido para a entrada!";
    }
};

class EntradaUtil {
public:
    static void removerEspacosInicioFim(std::string& str);
    static bool contemInteiro(const std::string& str);
    static void tornarCaixaAlta(std::string& str);
};

#endif // ENTRADAUTIL_HPP