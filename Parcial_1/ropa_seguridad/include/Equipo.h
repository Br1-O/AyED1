#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

class Equipo {
private:
    std::string nombre;
    int codigo;
    double precio;

public:
    Equipo(const std::string& nombre, int codigo, double precio);
    
    std::string getNombre() const;
    int getCodigo() const;
    double getPrecio() const;
};

#endif
