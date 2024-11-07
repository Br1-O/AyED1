#include "Cliente.h"

// Constructor  
Cliente::Cliente(const std::string& nombre, const std::string& telefono, const std::string& email)
    : nombre(nombre), telefono(telefono), email(email) {} // lista de inicialización


std::string Cliente::getNombre() const {
    return nombre;
}

std::string Cliente::getTelefono() const {
    return telefono;
}

std::string Cliente::getEmail() const {
    return email;
}
