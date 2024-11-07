#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
private:
    std::string nombre;
    std::string telefono;
    std::string email;

public:
    Cliente(const std::string& nombre, const std::string& telefono, const std::string& email);
    
    std::string getNombre() const;
    std::string getTelefono() const;
    std::string getEmail() const;
};

#endif
