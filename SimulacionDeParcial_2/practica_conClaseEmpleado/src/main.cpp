/* 
    Una Empresa que vende “cosméticos” nos convoca para la realización de una App que permita
    registrar los Pedidos de Artículos de los clientes.
    La misma debe permitir:
    1. Cargar Artículos.
    2. Cargar Clientes
    3. Cargar Pedidos de Artículos Asignados a los Clientes.
    4. Mostrar los pedidos de los Clientes.

    La aplicación deberá realizarse Implementando los Objetos Correspondientes. 
*/
#include <iostream>

#include "../include/Utils.hpp"
#include "../resources/data/data.hpp"

int main(int argc, char const *argv[])
{
    int optionSelected = 0;

    data::loadData();

    do
    {
        utils::displayMenu();
        utils::getSelectedOptionFromUser(&optionSelected);
        utils::pauseConsole();
        utils::clearConsole();
    } while (optionSelected != 10);
    
    return 0;
}
