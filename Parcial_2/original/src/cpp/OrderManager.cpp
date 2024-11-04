#include <iostream>
#include <list>
#include <string>
#include "../../include/Order.hpp"
#include "../../include/Article.hpp"
#include "../../include/OrderManager.hpp"
#include "../../include/ClientManager.hpp"
#include "../../include/ArticleManager.hpp"
#include "../../include/EmployeeManager.hpp"
#include "../../include/Utils.hpp"

using namespace std;

//■■■■■■■■■ getters ■■■■■■■■■//

//orders
list<Order*> OrderManager::getOrders() const
{
    return this->orders;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//orders
void OrderManager::setNewOrders(Order* order)
{
    (this->orders).push_back(order);
};

//■■■■■■■■■ constructor ■■■■■■■■■//

OrderManager::OrderManager(){};

OrderManager::OrderManager(
list<Order*> orders)
{
    this->orders=orders;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

OrderManager::~OrderManager(){

    //since my Manager classes are singletons, which are suppose to live through the whole app lifetime they don't implement a default destructor
    
};

//■■■■■■■■■ methods ■■■■■■■■■//

void OrderManager::displayActiveOrders(){

    list<Order*> currentOrders = OrderManager::defaultOrderManager.getOrders();

    string title = "Listado de ordenes activas: ";
    string lineSeparator =  "---------------------------------";

    cout << title << endl;

    if (currentOrders.size() > 0)
    {
        for (const auto& order:currentOrders)
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
    }else
    {
        cout << "No hay ordenes activas por el momento." << endl;
    }
};

list<Order*> OrderManager::getOrdersbyClientId(int id){
    
    list<Order*> foundOrders;

    list<Order*> currentOrders = OrderManager::defaultOrderManager.getOrders();

    for (const auto& order : currentOrders)
    {
        if (id == ( (order->getClient()).getId()) )
        {
            foundOrders.push_back(order);
        }
    }

    return foundOrders;
};

void OrderManager::displayActiveOrdersByClientId(){

    int clientId;

    cout << "Ingrese el id del cliente para mostrar los pedidos activos: " << endl;

    cin >> clientId;
    cin.ignore();

    if(OrderManager::defaultOrderManager.getOrdersbyClientId(clientId).size() > 0 )
    {
        utils::clearConsole();

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
    }
};

Order* OrderManager::generateOrder(ClientManager clientManagerInstance, ArticleManager articleManagerInstance, EmployeeManager EmployeeManagerInstance) {
    int id, clientId, employeeId, articleId, productUnits = 0;
    double totalCost = 0.0;
    Order* newOrder = nullptr;

    std::list<Article> articles;

    std::cout << "Por favor, ingrese el id del cliente: " << std::endl;
    std::cin >> clientId;
    std::cin.ignore();

    //fetch copy of the client's pointer
    Client clientCopy = clientManagerInstance.getClientById(clientId);

    if (clientCopy.getId() != 0) {

        utils::clearConsole();

        std::cout << "Por favor, ingrese el id del empleado que genera el pedido: " << std::endl;
        std::cin >> employeeId;
        std::cin.ignore();

        //fetch copy of the employee's pointer
        Employee employeeCopy = EmployeeManagerInstance.getEmployeeById(employeeId);

        if (employeeCopy.getId() != 0)
        {
            utils::clearConsole();

            std::cout << "Ingrese el id de los productos a incluir en el pedido." << std::endl;

            do {
                std::cout << "Para completar la carga del pedido, ingrese: 0" << std::endl << std::endl;

                std::cout << "Ingrese el id del producto: " << std::endl;
                std::cin >> articleId;
                std::cin.ignore();

                Article articleCopy = articleManagerInstance.getArticleById(articleId);

                if (articleCopy.getId() != 0) {
                    std::cout << "Ingrese la cantidad de unidades del producto: " << std::endl;
                    std::cin >> productUnits;
                    std::cin.ignore();

                    try {
                        utils::clearConsole();

                        //deep copy of article with quantity changed based on the order
                        articleCopy.setQuantity(productUnits);
                        articles.push_back(articleCopy);

                        std::cout << std::endl << "Producto agregado correctamente." << std::endl;

                    } catch (const std::exception& e) {
                        std::cerr << e.what() << '\n';
                        std::cout << std::endl << "No se pudo agregar el producto debido a un error." << std::endl;
                        
                    }
                } else if (articleId != 0) {
                    
                    std::cout << std::endl << "Producto no encontrado. Revise el id ingresado." << std::endl;

                }
            } while (articleId != 0);

            // Calculate total cost
            for (const auto& article : articles) {
                totalCost += article.getPrice() * article.getQuantity();
            }

            try {
                // Determine new order ID
                const auto& currentOrders = OrderManager::defaultOrderManager.getOrders();
                id = currentOrders.empty() ? 1 : (currentOrders.back()->getId() + 1);

                // Create a new Order with a unique copy of articles and client
                newOrder = new Order(id, clientCopy, employeeCopy, articles, totalCost);

                // Add the new order to the list
                OrderManager::defaultOrderManager.setNewOrders(newOrder);

                std::cout << "Orden agregada correctamente, con id: " << newOrder->getId() << std::endl;

            } catch (const std::exception& e) {
                std::cerr << e.what() << '\n';
                std::cout << "No se pudo crear la orden." << std::endl;
                delete newOrder;

            }
        }
    }

    return newOrder;
}

bool OrderManager::cancelOrder(int id){
    return false;
};

//■■■■■■■■■ default instance ■■■■■■■■■//

OrderManager OrderManager::defaultOrderManager;