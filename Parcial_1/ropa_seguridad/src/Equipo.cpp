#include "Equipo.h"


Equipo::Equipo(const std::string& nombre, int codigo, double precio)
    : nombre(nombre), codigo(codigo), precio(precio) {}  // lista de inicialización



std::string Equipo::getNombre() const {
    return nombre;
}

int Equipo::getCodigo() const {
    return codigo;
}

double Equipo::getPrecio() const {
    return precio;
}
