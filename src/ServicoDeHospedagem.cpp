#include "../include/ServicoDeHospedagem.hpp"

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

void ServicoDeHospedagem::listarHoteis() {
    RepositorioHotel repositorioHotel;
    std::vector<Hotel> hoteis = repositorioHotel.listarHoteis();
    std::cout << "\nHoteis disponíveis: " << std::endl;
    std::cout << std::setfill('-') << std::setw(42) << "" << std::endl;
    std::cout << std::setw(5) << std::left << "ID" << " | " << std::setw(20) << "Hotel" << std::endl;
    std::cout << std::setfill('-') << std::setw(42) << "" << std::endl;

    for(Hotel hotel : hoteis) {
        std::cout << std::setw(5) << std::left << hotel.getId() << " | " << std::setw(20) << hotel.getNome() << std::endl;
    }
    std::cout << std::endl;
}

void ServicoDeHospedagem::listarReservas(const std::unique_ptr<UsuarioCliente>& usuarioLogado) {
    
    std::vector<Reserva> reservas = repositorioReserva.listarReservas(usuarioLogado);

    std::cout << "\nReservas do Usuário: " << std::endl;
    std::cout << std::setfill('-') << std::setw(42) << "" << std::endl;
    std::cout << std::setw(30) << std::left << "Hotel" << " | " 
              << std::setw(20) << "Número do quarto" << " | " 
              << std::setw(15) << "Início" << " | " 
              << std::setw(15) << "Fim" << std::endl;
    std::cout << std::setfill('-') << std::setw(42) << "" << std::endl;

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

        std::cout << std::left << std::setw(30) << nomeHotel  << " | "  
                  << std::setw(20) << numeroQuarto  << " | "  
                  << std::setw(15) << dataInicio_ss.str()  << " | "
                  << std::setw(15) << dataFim_ss.str() << std::endl;
    }
    std::cout << std::endl;
}

void ServicoDeHospedagem::listarQuartos(std::string idHotel) {

    std::vector<Quarto> quartos = repositorioQuarto.listarQuartos(idHotel);

    if(quartos.empty()) {
       throw HotelNaoExisteOuNaoPossuiQuartoCadastradoException();
    }

    std::cout << "\nQuartos do hotel:" << std::endl;
    std::cout << std::setfill('-') << std::setw(42) << "" << std::endl;
    std::cout << std::setw(5) << std::left << "ID" << " | " 
              << std::setw(20) << "Número do quarto" << " | " 
              << std::setw(40) << "Localização" << std::endl;
    std::cout << std::setfill('-') << std::setw(42) << "" << std::endl;

    for (Quarto quarto : quartos) {
        std::cout << std::setw(5) << std::left << quarto.getId() << " | " 
            << std::setw(20) << quarto.getNumero() << " | "
            << std::setw(40) << quarto.getLocalizacao() << std::endl;
    }
    std::cout << std::endl;
}

void ServicoDeHospedagem::listarReservasDoQuarto(std::string idQuarto) {

    if(!repositorioQuarto.existeQuarto(idQuarto)) {
        throw QuartoNaoCadastradoException();
    }

    std::vector<Reserva> reservas = repositorioReserva.listarReservasDoQuarto(idQuarto);

    if (reservas.empty()) {
        std::cout << "\nO quarto selecionado ainda não possui nenhuma reserva." << std::endl;    
    } else {
        std::cout << "\nReservas para o quarto de ID " << reservas.front().getQuarto().getId() << ":" <<  std::endl;
        std::cout << std::setw(30) << std::left << "Hotel"
              << std::setw(20) << std::left << "Número do quarto"
              << std::setw(15) << std::left << "Início"
              << std::setw(15) << std::left << "Fim" << std::endl;

        for (Reserva reserva : reservas) {
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
            std::cout << std::endl;
        }
    }    

}

void ServicoDeHospedagem::exibeQuartos() {
    std::cout << "Informe o ID do Hotel para reserva: ";
    std::string id_hotel_escolhido = MenuUsuario::escolher_opcao();
    this->listarQuartos(id_hotel_escolhido);
}

std::string ServicoDeHospedagem::escolherQuarto() {
    std::cout << "Informe o ID do quarto para reserva: ";
    return MenuUsuario::escolher_opcao(); 
}

void ServicoDeHospedagem::reservarQuarto(const std::unique_ptr<UsuarioCliente>& usuarioLogado) {
    
    this->exibeQuartos();
    std::string id_quarto_escolhido = this->escolherQuarto();
    this->listarReservasDoQuarto(id_quarto_escolhido);
    
    std::cout << "Digite a data inicial da reserva (formato: DD-MM-YYYY): ";
    std::string dataInicioReserva;
    std::getline(std::cin, dataInicioReserva);
    EntradaUtil::removerEspacosInicioFim(dataInicioReserva);
    
    std::cout << "Digite a data final da reserva (formato: DD-MM-YYYY): ";
    std::string dataFinalReserva;
    std::getline(std::cin, dataFinalReserva);
    EntradaUtil::removerEspacosInicioFim(dataFinalReserva);
    
    std::istringstream ssInicio(dataInicioReserva);
    std::tm tmInicio = {};
    ssInicio >> std::get_time(&tmInicio, "%d-%m-%Y");
    tmInicio.tm_hour = 0;
    tmInicio.tm_min = 0;
    tmInicio.tm_sec = 0;
    std::chrono::system_clock::time_point dataInicio = std::chrono::system_clock::from_time_t(std::mktime(&tmInicio));
    if (ssInicio.fail()) {
        throw DataInvalidaException();
    }

    std::istringstream ssFinal(dataFinalReserva);
    std::tm tmFinal = {};
    ssFinal >> std::get_time(&tmFinal, "%d-%m-%Y");
    tmFinal.tm_hour = 0;
    tmFinal.tm_min = 0;
    tmFinal.tm_sec = 0;
    std::chrono::system_clock::time_point dataFinal = std::chrono::system_clock::from_time_t(std::mktime(&tmFinal));
    if (ssFinal.fail()) {
        throw DataInvalidaException();
    }

    size_t pos; 
    int id_quarto = std::stoi(id_quarto_escolhido, &pos);

    Reserva reserva(Quarto(id_quarto), dataInicio, dataFinal, *usuarioLogado);

    if (repositorioReserva.estaDisponivel(reserva)) {
        double precoFinal = reserva.calcularPrecoFinal();
        // Salva o locale atual
        const std::locale oldLocale = std::cout.imbue(std::locale("pt_BR.UTF-8"));
        std::cout << "Valor total da reserva: R$ " << std::fixed << std::setprecision(2) << precoFinal << std::endl;
        // Restaura o locale anterior
        std::cout.imbue(oldLocale);

        std::cout << "\nFormas de pagamento:" << std::endl;
        std::cout << FormaDePagamentoUtil::toString(FormaDePagamento::BOLETO)  << " - BOLETO" << std::endl;
        std::cout << FormaDePagamentoUtil::toString(FormaDePagamento::CARTAO_DE_CREDITO)  << " - CARTÃO DE CRÉDITO" << std::endl;
        std::cout << FormaDePagamentoUtil::toString(FormaDePagamento::PIX)  << " - PIX" << std::endl;
        std::cout << FormaDePagamentoUtil::toString(FormaDePagamento::CARTAO_DE_DEBITO)  << " - CARTÃO DE DÉBITO" << std::endl;
        std::cout << "Escolha a forma de pagamento: ";
        std::string opcao_forma_pagamento = MenuUsuario::escolher_opcao();

        reserva.setFormaDePagamento(FormaDePagamento(std::stoi(opcao_forma_pagamento)));                                        

        std::cout << "\nDeseja confirmar a reserva [S/N]? ";
        std::string opacao_confirma_reserva = MenuUsuario::escolher_opcao_str();
        
        EntradaUtil::tornarCaixaAlta(opacao_confirma_reserva);
        
        if (opacao_confirma_reserva == "S") {
            repositorioReserva.incluir(reserva);
            std::cout << "Reserva efetuada com sucesso!" << std::endl;
            std::cout << std::endl;
        } else {
            std::cout << "Reserva cancelada." << std::endl;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    } else {
        std::cout << "Quarto já reservado no período! Escolha outra data!" << std::endl;    
    }
}
