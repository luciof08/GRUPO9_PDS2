#include <iostream>
#include <memory>
#include <chrono>
#include <ctime>
#include <iomanip> 
#include <sstream> 
#include "../include/UsuarioCliente.hpp"
#include "../include/Quarto.hpp"
#include "../include/Hotel.hpp"
#include "../include/Reserva.hpp"
#include "../include/ServicoDeHospedagem.hpp"
#include "../include/MenuUsuario.hpp"
#include "../include/EntradaUtil.hpp"
 
int main() {

    MenuUsuario::mostrar_titulo_sistema();

    ServicoDeHospedagem servico;

    do {
        MenuUsuario::mostrar_menu_inicial();
        MenuUsuario::mostrar_opcao_encerrar();
        std::string opcao_escolhida_inicial = MenuUsuario::escolher_opcao();
        try {        
            if(opcao_escolhida_inicial == "1") {
                servico.cadastrarUsuario();
            } else if (opcao_escolhida_inicial == "2") {
                    std::unique_ptr<UsuarioCliente> usuarioLogado = servico.logarUsuario();
                    if (usuarioLogado != nullptr) {
                        do {
                            try {
                                MenuUsuario::mostrar_menu_usuario_logado();
                                MenuUsuario::mostrar_opcao_encerrar();
                                std::string opcao_escolhida_usuario = MenuUsuario::escolher_opcao();
                                if (opcao_escolhida_usuario == "1") {
                                    servico.listarHoteis();
                                } else if (opcao_escolhida_usuario == "2") {
                                    servico.listarReservas(usuarioLogado);
                                } else if(opcao_escolhida_usuario == "3") {
                                    servico.reservarQuarto(usuarioLogado);
                                } else if (opcao_escolhida_usuario == "0") {
                                    break;
                                } else {
                                    std::cout << "Opção inválida, tente novamente." << std::endl;
                                    continue;
                                }
                            } catch (std::exception &ex) {
                               std::cout << "Erro: " << ex.what() << std::endl;
                            }       
                        } while (true);
                    }
            } else if (opcao_escolhida_inicial == "0") {
                break;
            } else {
                std::cout << "Opção inválida, tente novamente." << std::endl;
                continue;
            }
        } catch (std::exception &ex) {
            std::cout << "Erro: " << ex.what() << std::endl;
        }

    } while(true);

    return 0;
}