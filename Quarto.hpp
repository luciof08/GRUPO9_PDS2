#ifndef QUARTO_HPP
#define QUARTO_HPP

#include "Hotel.hpp" // Supondo que a classe Hotel já está definida em Hotel.hpp

class Quarto {
private:
    int id;
    int numero;
    std::string localizacao;
    Hotel hotel;

public:

    Quarto();

    // Construtor
    Quarto(int id);

    Quarto(int id, int numero, Hotel& hotel);

    Quarto(int id, int numero, std::string localizacao, const Hotel& hotel);

    // Getters
    int getId() const;
    int getNumero() const;
    std::string getLocalizacao() const;
    Hotel getHotel() const;

    // Setters
    void setId(int id);
    void setNumero(int numero);
    void setHotel(const Hotel& hotel);
};

#endif /* QUARTO_HPP */