#include "ConexaoBancoDeDados.hpp"

ConexaoBancoDeDados::ConexaoBancoDeDados() {
    this->dbname = "postgres";
    this->user = "postgres";
    this->password = "1234";
    this->host = "localhost"; 
    connection = std::make_unique<pqxx::connection>("dbname=" + this->getDBName() + 
                                           " user=" + this->getUser() + 
                                           " password=" + this->getPassword() +
                                           " host=" + this->getHost());
    if (!connection->is_open()) {
        throw std::runtime_error("Falha ao conectar ao banco de dados.");
    }
}
    
std::string ConexaoBancoDeDados::getDBName() const {
    return dbname;
}

std::string ConexaoBancoDeDados::getUser() const {
    return user;
}

std::string ConexaoBancoDeDados::getPassword() const {
    return password;
}

std::string ConexaoBancoDeDados::getHost() const {
    return host;
}

pqxx::connection& ConexaoBancoDeDados::getConnection() {
    return *connection;
}