#include <iostream>
#include "../../include/ArticleManager.hpp"
#include "../../include/ClientManager.hpp"
#include "../../include/OrderManager.hpp"
#include "../../include/Utils.hpp"

using namespace std;

namespace utils
{
    //funtion to display the menu
    void displayMenu(){

        const string title = "--- Cosmeticos La Pestaña Aña ---";
        const string message = "- Por favor, ingrese el numero de la accion que desea realizar -";

        const int numberOfOptions = 5;
        string menu[numberOfOptions] = 
        {
            "1. Visualizar el listado de pedidos.",
            "2. Agregar un nuevo articulo.",
            "3. Agregar un nuevo cliente.",
            "4. Generar un nuevo pedido.",
            "5. Salir."
        };

        cout << title << endl;
        cout << message << endl << endl;

        for (size_t i = 0; i < numberOfOptions; i++)
        {
            cout << menu[i] << endl;
        }

        cout << endl;
    };

    //get selected option from user
    void getSelectedOptionFromUser(int* selectedOption){

        checkInputValueForInteger(selectedOption);

        //ignore remaining break line
        cin.ignore();

        switch (*selectedOption)
        {
            //display orders list
            case 1:
                clearConsole();

                OrderManager::defaultOrderManager.displayActiveOrders();

                pauseConsole();
            break;

            //create a new article
            case 2:
            {            
                clearConsole();

                ArticleManager::defaultArticleManager.loadNewArticle();

                pauseConsole();
            }
            break;

            //insert a new client
            case 3:
                clearConsole();

                ClientManager::defaultClientManager.loadNewClient();
                
                pauseConsole();
            break;

            //delete a student
            case 4:
            {            
                clearConsole();

                OrderManager::defaultOrderManager.generateOrder();
                
                pauseConsole();
            }
            break;

            //exit the program
            case 5:
                *selectedOption = 999;
            break;
            
            //invalid input
            default:
                cout << "Por favor, ingrese una opcion valida." << endl << endl;
            break;
        }
    };

    //check input value
    void checkInputValueForInteger(int* inputVariable, string errorMessage){

        //check if input is valid
        while (!(cin >> *inputVariable)) {

            cout << errorMessage;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    };

    //pause the console
    void pauseConsole(){
        #ifdef _WIN32 // For Windows
            std::cout << "Presione una tecla para volver al menu . . . ";
            std::cin.get(); // Wait for the user to press a key
        #else // For Linux and other Unix-like systems
            std::cout << "Presione una tecla para volver al menu . . . ";
            std::cin.ignore(); // Ignore any previous input
            std::cin.get(); // Wait for the user to press Enter
        #endif
    };

    //clean the console
    void clearConsole(){
        #ifdef _WIN32 // For Windows
            system("cls"); // Clear the console using cls command
        #else // For Linux and other Unix-like systems
            system("clear"); // Clear the console using clear command
        #endif
    };
} // namespace utils