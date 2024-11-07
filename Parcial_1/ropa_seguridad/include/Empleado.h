#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

class Empleado {
private:
    std::string nombre;
    std::string ID;
    

public:
    Empleado(const std::string& nombre, const std::string& ID);
             
    std::string getNombre() const;
    std::string getID() const;

};

#endif
