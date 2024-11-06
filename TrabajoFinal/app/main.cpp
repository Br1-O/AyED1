#include <iostream>

#include "utils/include/Utils.hpp"
#include "utils/include/FileHandler.hpp"

//use for easy data handling testing
//#include "businessService/resources/data/dataExample.hpp"

//■■■■■■ Menu building ■■■■■■//

const std::string title = "--- El carnero testarudo - Boutique de carnes ---";
const std::string message = "- Por favor, ingrese el numero de la accion que desea realizar -";

const int numberOfOptionsBusiness = 10;
std::string menuBusiness[numberOfOptionsBusiness] = 
{
    "1. Visualizar el listado de pedidos.",
    "2. Agregar un nuevo articulo.",
    "3. Agregar un nuevo cliente.",
    "4. Generar un nuevo pedido.",
    "5. Visualizar el listado de articulos.",
    "6. Visualizar el listado de clientes.",
    "7. Visualizar el listado de empleados.",
    "8. Buscar pedido de cliente.",
    "9. Agregar un nuevo empleado.",
    "10. Salir."
};

const std::string titleInventory = "--- Gestion de inventario: ---";
const std::string messageInventory = " ";

const int numberOfOptionsInventory = 5;
std::string menuInventory[numberOfOptionsInventory] = 
{           
    "11. Visualizar el listado de inventario de carnes.",
    "12. Visualizar el listado de inventario de productos.",
    "13. Agregar una manufacturacion de producto carnico.",
    "14. Agregar re stock de carne.",
    "15. Agregar un nuevo tipo de carne.",
};

//■■■■■■ Main ■■■■■■//

int main(int argc, char const *argv[])
{
    int optionSelected = 0;

    if((FileHandler::defaultFileHandler).loadDataFromFile()){
        do
        {
            utils::displayMenu(title, message, numberOfOptionsBusiness, menuBusiness);
            utils::displayMenu(titleInventory, messageInventory, numberOfOptionsInventory, menuInventory);
            utils::getSelectedOptionFromUser(&optionSelected);

            if(optionSelected != 10)
            {
                utils::pauseConsole();
                utils::clearConsole();
            }
        } while (optionSelected != 10);

    }else{
        std::cout << "No se ha cargado correctamente el archivo, revise que el archivo se encuentre en la ruta predefinida y no este corrupto." << std::endl;

        utils::pauseConsole("Presione una tecla para terminar el programa.");
    };
    
    return 0;
}
