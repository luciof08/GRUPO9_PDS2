#include "Quarto.hpp"

// Construtor
Quarto::Quarto(int id) : id(id) {}

Quarto::Quarto(int id, int numero, Hotel& hotel) : id(id), numero(numero), hotel(hotel) {}

Quarto::Quarto(int id, int numero, std::string localizacao,const Hotel& hotel) : id(id), numero(numero),localizacao(localizacao), hotel(hotel) {}

// Getters
int Quarto::getId() const {
    return id;
}

int Quarto::getNumero() const {
    return numero;
}

std::string Quarto::getLocalizacao() const {
    return localizacao;
}

Hotel Quarto::getHotel() const {
    return hotel;
}

// Setters
void Quarto::setId(int id) {
    this->id = id;
}

void Quarto::setNumero(int numero) {
    this->numero = numero;
}

void Quarto::setHotel(const Hotel& hotel) {
    this->hotel = hotel;
}