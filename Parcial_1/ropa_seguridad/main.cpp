#include <iostream>
#include "./include/Equipo.h"
#include "./include/Cliente.h"
#include "./include/Pedido.h"
#include "./include/Empleado.h"

int main() {

    // Crear empleados
    Empleado empleado1("JULIETA", "EM888");
    Empleado empleado2("MATEO", "EM999");

    // Crear clientes
    Cliente cliente1("Andrea Lopez", "223-5758077", "andreita@email.com");
    Cliente cliente2("Juan Perez", "223-5121212", "perezju@email.com");
    Cliente cliente3("Mauro Godoy", "223-5777888", "mari@email.com");
    Cliente cliente4("Laura Sosa", "223-6567890", "lauri@mail.com");

    // Crear Equipos dinámicamente
    Equipo* Equipo1 = new Equipo("Antiparras", 101, 1500.99);
    Equipo* Equipo2 = new Equipo("Botin Punta-Acero", 102, 29000.00);
    Equipo* Equipo3 = new Equipo("Pantalon Refractario", 103, 32000.00);
    Equipo* Equipo4 = new Equipo("Chaleco Fluo", 104, 1800.00);
    Equipo* Equipo5 = new Equipo("Arnes Seguridad", 105, 8200.00);

    // Crear pedido
    Pedido pedido1(&cliente1, &empleado1); 
    Pedido pedido2(&cliente2, &empleado2);
    Pedido pedido3(&cliente3, &empleado1);
    Pedido pedido4(&cliente4, &empleado2);
    
    // Agregar artículos al pedido
    pedido1.agregarEquipos(Equipo1);
    pedido1.agregarEquipos(Equipo2);
    pedido2.agregarEquipos(Equipo4);
    pedido3.agregarEquipos(Equipo3);
    pedido4.agregarEquipos(Equipo1);
    pedido4.agregarEquipos(Equipo5);

    // Ver los pedidos
    std::cout << "\n** PICHA SEGURA SHOP **\n";
    pedido1.verPedido();
    pedido2.verPedido();
    pedido3.verPedido();
    pedido4.verPedido();

    // Libera memoria
    delete Equipo1;
    delete Equipo2;
    delete Equipo3;
    delete Equipo4;
    delete Equipo5;

    return 0;
}
