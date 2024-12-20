#include <iostream>

#include "utils/include/Utils.hpp"
#include "utils/include/FileHandler.hpp"

//use for easy data handling testing
//#include "businessService/resources/data/dataExample.hpp"
#include "inventoryService/resources/data/dataInventoryExample.hpp"

//■■■■■■ Menu building ■■■■■■//

const std::string title = "--- Ukelele Chicken - Boutique de carnes ---";
const std::string message = "- Por favor, ingrese el numero de la accion que desea realizar -";

const int numberOfOptionsBusiness = 10;
std::string menuBusiness[numberOfOptionsBusiness] = 
{
    "1. Visualizar el listado de pedidos.",
    "2. Agregar un nuevo producto.",
    "3. Agregar un nuevo cliente.",
    "4. Generar un nuevo pedido.",
    "5. Visualizar el listado de productos.",
    "6. Visualizar el listado de clientes.",
    "7. Visualizar el listado de empleados.",
    "8. Buscar pedido de cliente.",
    "9. Agregar un nuevo empleado.",
    "10. Salir."
};

const std::string titleInventory = "--- Gestion de inventario de carnes: ---";
const std::string messageInventory = " ";

const int numberOfOptionsInventory = 2;
std::string menuInventory[numberOfOptionsInventory] = 
{           
    "11. Visualizar el listado de inventario de carnes.",
    "12. Agregar re stock de carne.",
};

//■■■■■■ Main ■■■■■■//

int main(int argc, char const *argv[])
{
    int optionSelected = 0;

    dataInventoryExample::loadData();

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
