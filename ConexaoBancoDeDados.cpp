#include "ConexaoBancoDeDados.hpp"

ConexaoBancoDeDados::ConexaoBancoDeDados() {
    this->dbname = "postgres";
    this->user = "postgres";
    this->password = "1234";
    this->host = "localhost"; 
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