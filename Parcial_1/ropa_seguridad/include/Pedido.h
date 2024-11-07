#ifndef PEDIDO_H
#define PEDIDO_H

#include "Equipo.h"
#include "Cliente.h"
#include "Empleado.h"
#include <iostream>

class Pedido {
private:
    int nroPedido;
    Cliente* cliente;
    Empleado* empleado;
    Equipo* Equipos[10]; // Array de punteros a Equipo
    int cantidadEquipos;
    
   static int contadorPedidos; // Atributo para contar pedidos

public:
    Pedido(Cliente* cliente, Empleado* empleado);
           
    void agregarEquipos(Equipo* Equipo);
    void verPedido() const;
};

#endif
