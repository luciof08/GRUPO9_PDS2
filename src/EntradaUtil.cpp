#include "../include/EntradaUtil.hpp"
#include <cctype>

void EntradaUtil::removerEspacosInicioFim(std::string& str) {
    // Remove espaços em branco no início da string
    size_t inicio = str.find_first_not_of(" \t\n\r\f\v");
    if (inicio != std::string::npos) {
        str.erase(0, inicio);
    }

    // Remove espaços em branco no final da string
    size_t fim = str.find_last_not_of(" \t\n\r\f\v");
    if (fim != std::string::npos) {
        str.erase(fim + 1);
    } else {
        // Se a string estiver vazia ou contendo apenas espaços, limpa a string
        str.clear();
    }
}

bool EntradaUtil::contemInteiro(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (const std::exception& e) {
        return false;
    }
}

void EntradaUtil::tornarCaixaAlta(std::string& str) {
    for (char &c : str) {
        c = std::toupper(c);
    }
}

std::string EntradaUtil::lerSenha() {
    struct termios original_termios;
    termios tty;
    tcgetattr(STDIN_FILENO, &original_termios);
    tty = original_termios;
    tty.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
    std::string senha;
    std::getline(std::cin, senha);
    tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
    return senha;
}