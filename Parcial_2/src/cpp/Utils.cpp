#include <iostream>
#include "../../include/ArticleManager.hpp"
#include "../../include/ClientManager.hpp"
#include "../../include/EmployeeManager.hpp"
#include "../../include/OrderManager.hpp"
#include "../../include/Utils.hpp"

using namespace std;

namespace utils
{
    //funtion to display the menu
    void displayMenu(){

        const string title = "--- Los gases nobles S.A. ---";
        const string message = "- Por favor, ingrese el numero de la accion que desea realizar -";

        const int numberOfOptions = 10;
        string menu[numberOfOptions] = 
        {
            "1. Visualizar el listado de pedidos.",
            "2. Agregar un nuevo articulo.",
            "3. Agregar un nuevo cliente.",
            "4. Generar un nuevo pedido.",
            "5. Visualizar el listado de articulos.",
            "6. Visualizar el listado de clientes.",
            "7. Buscar pedido de cliente.",
            "8. Visualizar el listado de empleados.",
            "9. Agregar un nuevo empleado.",
            "10. Salir.",
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
            break;

            //create a new article
            case 2:
            {            
                clearConsole();

                ArticleManager::defaultArticleManager.loadNewArticle();
            }
            break;

            //insert a new client
            case 3:
                clearConsole();

                ClientManager::defaultClientManager.loadNewClient();
            break;

            //generate a new order
            case 4:
            {            
                clearConsole();

                OrderManager::defaultOrderManager.generateOrder();
            }
            break;

            //display list of articles
            case 5:
            {            
                clearConsole();

                ArticleManager::defaultArticleManager.displayArticleList();
            }
            break;

            //display list of clients
            case 6:
            {            
                clearConsole();

                ClientManager::defaultClientManager.displayClientList();
            }
            break;

            //search an order based on client's id
            case 7:
            {            
                clearConsole();

                int clientId;

                cout << "Ingrese el id del cliente para mostrar los pedidos activos: " << endl;

                cin >> clientId;
                cin.ignore();

                if(OrderManager::defaultOrderManager.getOrdersbyClientId(clientId).size() > 0 )
                {
                    string lineSeparator =  "---------------------------------";

                    cout << "Hay pedidos pendientes para el cliente."<< endl << endl;

                    for (const auto& order: (OrderManager::defaultOrderManager.getOrdersbyClientId(clientId)))
                    {

                        cout << lineSeparator << endl;
                        cout << "Orden: " << order->getId() << endl;

                        cout << "Cliente: " << (order->getClient()).getName() << " " << (order->getClient()).getLastName() 
                            << " - id: " << (order->getClient()).getId() << endl << endl;

                        cout << "Empleado: " << (order->getEmployee()).getFirstName() << " " << (order->getEmployee()).getLastName() 
                        << " - id: " << (order->getEmployee()).getId() << endl << endl;

                        cout << "Pedido: " << endl;

                        for (const auto article : order->getArticles())
                        {
                            cout << "> " << article.getName() << " - " << "Cantidad: " << article.getQuantity() << endl;
                        }
                        
                        
                        cout << endl << "Total: $" << order->getTotalCost() << endl;

                        cout << lineSeparator << endl;
                    }


                }else{
                    cout << "No hay pedidos pendientes para el cliente.";

                }
            }
            break;

            //display list of employees
            case 8:
            {            
                clearConsole();

                EmployeeManager::defaultEmployeeManager.displayEmployeeList();
            }
            break;

            //load a new employee
            case 9:
            {            
                clearConsole();

                EmployeeManager::defaultEmployeeManager.loadNewEmployee();
            }
            break;

            //exit the program
            case 10:
                *selectedOption = 10;
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