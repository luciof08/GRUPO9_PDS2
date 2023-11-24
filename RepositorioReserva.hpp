#ifndef REPOSITORIORESERVA_HPP
#define REPOSITORIORESERVA_HPP

#include <vector>
#include "Reserva.hpp" 
#include "UsuarioCliente.hpp" 
#include "ConexaoBancoDeDados.hpp"

class RepositorioReserva {
private:
    ConexaoBancoDeDados conexao;
public:
    std::vector<Reserva> listarReservas(const std::unique_ptr<UsuarioCliente>& usuario);
    void incluir(const Reserva& reserva);
};

#endif /* REPOSITORIORESERVA_HPP */