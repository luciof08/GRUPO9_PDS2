#ifndef REPOSITORIORESERVA_HPP
#define REPOSITORIORESERVA_HPP

#include <vector>
#include "Reserva.hpp" 
#include "UsuarioCliente.hpp" 
#include "ConexaoBancoDeDados.hpp"
#include "FormaDePagamentoUtil.hpp"

class RepositorioReserva {
private:
    ConexaoBancoDeDados conexao;
public:
    std::vector<Reserva> listarReservas(const std::unique_ptr<UsuarioCliente>& usuario);
    std::vector<Reserva> listarReservasDoQuarto(std::string idQuarto); 
    void incluir(const Reserva& reserva);
    bool estaDisponivel(const Reserva& reserva);
};

#endif /* REPOSITORIORESERVA_HPP */