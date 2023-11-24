#include <iostream>
#include <memory>
#include <chrono>
#include <ctime>
#include <iomanip> 
#include <sstream> 
#include "UsuarioCliente.hpp"
#include "RepositorioHotel.hpp"
#include "Quarto.hpp"
#include "Hotel.hpp"
#include "Reserva.hpp"
#include "RepositorioReserva.hpp"
#include "RepositorioQuarto.hpp"


void cadastrar_usuario() {
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

std::unique_ptr<UsuarioCliente> realizar_login() {
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

void mostrar_opcao_encerrar() {
    std::cout << "0 - Encerrar" << std::endl;
}

void mostrar_menu_inicial() {
    std::cout << "Escolha uma opção:" << std::endl;
    std::cout << "1 - Cadastro" << std::endl;
    std::cout << "2 - Login" << std::endl;
}

std::string escolher_opcao() {
    std::string opcao;
    std::getline(std::cin, opcao);
    return opcao;
}

void mostrar_menu_usuario_logado() {
    std::cout << "Escolha uma opção:" << std::endl;
    std::cout << "1 - Listar Hoteis" << std::endl;
    std::cout << "2 - Reservas Realizadas" << std::endl;
    std::cout << "3 - Reservar Quarto" << std::endl;
}

void listar_hoteis() {
    RepositorioHotel repositorioHotel;
    std::vector<Hotel> hoteis = repositorioHotel.listarHoteis();
    std::cout << "\nHoteis disponíveis: " << std::endl;
    std::cout << std::setw(5) << std::left << "ID"
              << std::setw(30) << std::left << "Hotel" << std::endl;

    for(Hotel hotel : hoteis) {
        std::cout << std::setw(5) << std::left << hotel.getId()
            << std::setw(30) << std::left << hotel.getNome() << std::endl;
    }
}

void listar_reservas(const std::unique_ptr<UsuarioCliente>& usuarioLogado) {
    RepositorioReserva repositorioReserva;
    std::vector<Reserva> reservas = repositorioReserva.listarReservas(usuarioLogado);

    std::cout << "\nReservas do Usuário: " << std::endl;
    std::cout << std::setw(30) << std::left << "Hotel"
              << std::setw(20) << std::left << "Número do quarto"
              << std::setw(15) << std::left << "Início"
              << std::setw(15) << std::left << "Fim" << std::endl;

    for(Reserva reserva : reservas) {
         // Convertendo para std::time_t
        std::time_t dataInicio = std::chrono::system_clock::to_time_t(reserva.getDataInicio());
        std::time_t dataFim = std::chrono::system_clock::to_time_t(reserva.getDataFim());

        // Convertendo std::time_t para std::tm (Local Time)
        std::tm dataInicio_tm = *std::localtime(&dataInicio);
        std::tm dataFim_tm = *std::localtime(&dataFim);

        // Formatando datas para o formato dd/mm/yyyy
        std::stringstream dataInicio_ss, dataFim_ss;
        dataInicio_ss << std::put_time(&dataInicio_tm, "%d/%m/%Y");
        dataFim_ss << std::put_time(&dataFim_tm, "%d/%m/%Y");

        std::string nomeHotel = reserva.getQuarto().getHotel().getNome();
        int numeroQuarto = reserva.getQuarto().getNumero();

        std::cout << std::setw(30) << std::left << nomeHotel
                  << std::setw(20) << std::left << numeroQuarto
                  << std::setw(15) << std::left << dataInicio_ss.str()
                  << std::setw(15) << std::left << dataFim_ss.str() << std::endl;
    }
}

void listar_quartos(std::string idHotel) {

    RepositorioQuarto repositorio;
    std::vector<Quarto> quartos = repositorio.listarQuartos(idHotel);

    std::cout << "\nQuartos do hotel:" << std::endl;
    std::cout << std::setw(5) << std::left << "ID"
              << std::setw(20) << std::left << "Número do quarto"
              << std::setw(40) << std::left << "Localização" << std::endl;
            
    for (Quarto quarto : quartos) {
        std::cout << std::setw(5) << std::left << quarto.getId()
            << std::setw(20) << std::left << quarto.getNumero()
            << std::setw(40) << std::left << quarto.getLocalizacao() << std::endl;
    }
}
 
int main() {
    
    do {
        mostrar_menu_inicial();
        mostrar_opcao_encerrar();
        std::string opcao_escolhida_inicial = escolher_opcao();
        try {        
            if(opcao_escolhida_inicial == "1") {
                cadastrar_usuario();
            } else if (opcao_escolhida_inicial == "2") {
                    std::unique_ptr<UsuarioCliente> usuarioLogado = realizar_login();
                    if (usuarioLogado != nullptr) {
                        do {
                            try {
                                mostrar_menu_usuario_logado();
                                mostrar_opcao_encerrar();
                                std::string opcao_escolhida_usuario = escolher_opcao();
                                if (opcao_escolhida_usuario == "1") {
                                    listar_hoteis();
                                } else if (opcao_escolhida_usuario == "2") {
                                    listar_reservas(usuarioLogado);
                                } else if(opcao_escolhida_usuario == "3") {
                                    std::cout << "Informe o ID do Hotel para reserva: ";
                                    std::string id_hotel_escolhido = escolher_opcao();
                                    listar_quartos(id_hotel_escolhido);
                                    std::cout << "Informe o ID do quarto para reserva: ";
                                    std::string id_quarto_escolhido = escolher_opcao(); 
                                    
                                    std::cout << "Digite a data inicial da reserva (formato: DD-MM-YYYY): ";
                                    std::string dataInicioReserva;
                                    std::getline(std::cin, dataInicioReserva);
                                    std::cout << "Digite a data final da reserva (formato: DD-MM-YYYY): ";
                                    std::string dataFinalReserva;
                                    std::getline(std::cin, dataFinalReserva);
                                    
                                    std::istringstream ssInicio(dataInicioReserva);
                                    std::tm tmInicio = {};
                                    ssInicio >> std::get_time(&tmInicio, "%d-%m-%Y");
                                    tmInicio.tm_hour = 0;
                                    tmInicio.tm_min = 0;
                                    tmInicio.tm_sec = 0;
                                    std::chrono::system_clock::time_point dataInicio = std::chrono::system_clock::from_time_t(std::mktime(&tmInicio));
                                    if (ssInicio.fail()) {
                                        // OBS.: lançar exceção aqui ou fazer verificação quando construir o objeto de Reserva
                                        std::cout << "Formato inválido!" << std::endl;
                                    } else {
                                        // Utilize 'dataInicio' conforme necessário
                                        std::cout << "Data lida: " << std::chrono::system_clock::to_time_t(dataInicio) << std::endl;
                                    }
                                    std::istringstream ssFinal(dataFinalReserva);
                                    std::tm tmFinal = {};
                                    ssFinal >> std::get_time(&tmFinal, "%d-%m-%Y");
                                    tmFinal.tm_hour = 0;
                                    tmFinal.tm_min = 0;
                                    tmFinal.tm_sec = 0;
                                    std::chrono::system_clock::time_point dataFinal = std::chrono::system_clock::from_time_t(std::mktime(&tmFinal));
                                    if (ssFinal.fail()) {
                                        // OBS.: lançar exceção aqui ou fazer verificação quando construir o objeto de Reserva
                                        std::cout << "Formato inválido!" << std::endl;
                                    } else {
                                        // Utilize 'dataInicio' conforme necessário
                                        std::cout << "Data lida: " << std::chrono::system_clock::to_time_t(dataFinal) << std::endl;
                                    }
                                    size_t pos; 
                                    int id_quarto = std::stoi(id_quarto_escolhido, &pos);

                                    Reserva reserva(Quarto(id_quarto), dataInicio, dataFinal, *usuarioLogado);

                                    RepositorioReserva repositorioReserva;

                                    if (repositorioReserva.estaDisponivel(reserva)) {
                                        repositorioReserva.incluir(reserva);
                                        std::cout << "Reserva efetuada com sucesso!!" << std::endl;
                                    } else {
                                        std::cout << "Quarto já reservado no período! Escolha outra data!" << std::endl;    
                                    }
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