#include <iostream>
#include "../../businessService/include/controller/ArticleManager.hpp"
#include "../../businessService/include/controller/ClientManager.hpp"
#include "../../businessService/include/controller/EmployeeManager.hpp"
#include "../../businessService/include/controller/OrderManager.hpp"
#include "../../inventoryService/include/controller/MeatManager.hpp"
#include "../include/Utils.hpp"
#include "../include/FileHandler.hpp"

using namespace std;

namespace utils
{
    //funtion to display the menu
    void displayMenu(const std::string& title, const std::string& message, const int numberOfOptions, const std::string listOfOptions[]){

        // const string guideTemplateForMenuBody[10] =
        // {
        //     "1. Visualizar el listado de pedidos.",
        //     "2. Agregar un nuevo articulo.",
        //     "3. Agregar un nuevo cliente.",
        //     "4. Generar un nuevo pedido.",
        //     "5. Visualizar el listado de articulos.",
        //     "6. Visualizar el listado de clientes.",
        //     "7. Visualizar el listado de empleados.",
        //     "8. Buscar pedido de cliente.",
        //     "9. Agregar un nuevo empleado.",
        //     "10. Salir."
        // };

        cout << title << endl;
        cout << message << endl << endl;

        for (size_t i = 0; i < numberOfOptions; i++)
        {
            cout << listOfOptions[i] << endl;
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
            break;

            //create a new article
            case 2:        
                clearConsole();

                ArticleManager::defaultArticleManager.loadNewArticle();

                FileHandler::defaultFileHandler.saveDataIntoFile();
            break;

            //insert a new client
            case 3:
                clearConsole();

                ClientManager::defaultClientManager.loadNewClient();

                FileHandler::defaultFileHandler.saveDataIntoFile();
            break;

            //generate a new order
            case 4:
                clearConsole();

                OrderManager::defaultOrderManager.generateOrder();

                FileHandler::defaultFileHandler.saveDataIntoFile();
            break;

            //display list of articles
            case 5:
                clearConsole();

                ArticleManager::defaultArticleManager.displayArticleList();
            break;

            //display list of clients
            case 6:
                clearConsole();

                ClientManager::defaultClientManager.displayClientList();
            break;

            //display list of employees
            case 7:
                clearConsole();

                EmployeeManager::defaultEmployeeManager.displayEmployeeList();
            break;

            //search an order based on client's id
            case 8:
                clearConsole();

                OrderManager::defaultOrderManager.displayActiveOrdersByClientId();
            break;

            //load a new employee
            case 9:
                clearConsole();

                EmployeeManager::defaultEmployeeManager.loadNewEmployee();

                FileHandler::defaultFileHandler.saveDataIntoFile();
            break;

            //exit the program
            case 10:
                *selectedOption = 10;
            break;

            //display list of meat inventory
            case 11:
                clearConsole();

                MeatManager::defaultMeatManager.displayInventoryList();
            break;

            //add new meat stock into meat inventory
            case 12:
                clearConsole();

                MeatManager::defaultMeatManager.loadNewItem();

                FileHandler::defaultFileHandler.saveDataIntoFile();
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
    void pauseConsole(string message){
        #ifdef _WIN32 // For Windows
            std::cout << message;
            std::cin.get(); // Wait for the user to press a key
        #else // For Linux and other Unix-like systems
            std::cout << message;
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