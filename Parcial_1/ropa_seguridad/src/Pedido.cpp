#include <iostream>
#include "Pedido.h"

// Inicializo del contador de pedidos
int Pedido::contadorPedidos = 101;

Pedido::Pedido (Cliente* cliente, Empleado* empleado)
    : nroPedido(contadorPedidos++), cliente(cliente), cantidadEquipos(0), empleado(empleado) {}


void Pedido::agregarEquipos(Equipo* Equipo) {
    if (cantidadEquipos < 10) {  // para que no exceda el límite
        Equipos[cantidadEquipos++] = Equipo; 
    }
}


void Pedido::verPedido() const {
    
    std::cout << "Pedido nro.:" << nroPedido << "   - Para: " << cliente->getNombre() << "\nEquipos:\n";
    for (int i = 0; i < cantidadEquipos; ++i) {
        std::cout << "- " << Equipos[i]->getNombre()
                  << " (Codigo: " << Equipos[i]->getCodigo()
                  << ", Precio: $" << Equipos[i]->getPrecio() << ")\n";
    }
    std::cout << "||Atendido por: " << empleado->getNombre() << " - ID: " <<empleado->getID() << "|| \n";

}
