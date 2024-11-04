#include <iostream>

#include "../include/Utils.hpp"
#include "../include/FileHandler.hpp"

//use for easy data handling testing
//#include "../resources/data/dataExample.hpp"

int main(int argc, char const *argv[])
{
    int optionSelected = 0;

    if((FileHandler::defaultFileHandler).loadDataFromFile()){
        do
        {
            utils::displayMenu();
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
