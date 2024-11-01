#include <iostream>
#include <list>
#include <string>
#include "../../include/Order.hpp"
#include "../../include/Article.hpp"
#include "../../include/OrderManager.hpp"
#include "../../include/ClientManager.hpp"
#include "../../include/ArticleManager.hpp"
#include "../../include/Utils.hpp"

using namespace std;

//■■■■■■■■■ getters ■■■■■■■■■//

//orders
list<Order*> OrderManager::getOrders()
{
    return this->orders;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//orders
void OrderManager::setOrders(list<Order*> orders)
{
    this->orders=orders;
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
    for (Order* order : orders) {
    delete order;
    }
};

//■■■■■■■■■ methods ■■■■■■■■■//

void OrderManager::displayActiveOrders(){

    list<Order*> currentOrders = OrderManager::getOrders();

    string title = "Listado de ordenes activas: ";
    string lineSeparator =  "---------------------------------";

    cout << title << endl;

    for (Order* order:currentOrders)
    {
        cout << lineSeparator << endl;
        cout << "Orden: " << order->getId() << endl;
        cout << "Cliente: " << (order->getClient()).getName() << " " << (order->getClient()).getLastName() 
             << " - id: " << (order->getClient()).getId() << endl << endl;

        cout << "Pedido: " << endl;

        for (Article* article : order->getArticles())
        {
            cout << "> " << article->getName() << " - " << "Cantidad: " << article->getQuantity() << endl;
        }
        
        
        cout << endl << "Total: $" << order->getTotalCost() << endl;

        cout << lineSeparator << endl;
    }

    utils::pauseConsole();
};

Order* OrderManager::getOrdersbyClientId(int id){
    
    Order* searchedOrder = nullptr;

    list<Order*> currentOrders = OrderManager::getOrders();

    for (Order* order : currentOrders)
    {
        if (id == ( (order->getClient()).getId()) )
        {
            searchedOrder = order;
            break;
        }
    }

    return searchedOrder;
};

Order* OrderManager::generateOrder(ClientManager clientManagerInstance, ArticleManager articleManagerInstance){

    int id, clientId, articleId, productUnits;
    Client* client = nullptr;
    Article* article = nullptr;
    list<Article*> articles;
    double totalCost;

    Order* newOrder = nullptr;

    cout << "Por favor, ingrese el id del cliente: " << endl;
    cin >> clientId;
    cin.ignore();

    client = clientManagerInstance.getClientById(clientId);

    if(client)
    {
        utils::clearConsole();

        cout << "A continuacion ingrese el id de los productos a incluirse en el pedido. " << endl;
        cout << "Cuando haya terminado de incluir productos al pedido ingrese: 0" << endl;

        do
        {
            cout << "Ingrese el id del producto: " << endl;
            cin >> articleId;
            cin.ignore();

            article = articleManagerInstance.getArticleById(articleId);

            //to do: validation to check if article is already in the list, so quantity++
            if (article)
            {
                cout << "Ingrese la cantidad de unidades del producto a incluirse en el pedido: " << endl;
                cin >> productUnits;
                cin.ignore();

                try
                {
                    article->setQuantity(productUnits);
                    articles.push_back(article);
                    cout<< endl << "¡Producto agregado correctamente!" << endl << endl;
                    article = nullptr;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                    cout << "¡Por esta razon no se pudo crear la orden!";
                }
            }else{
                cout<< endl << "No se pudo encontrar el producto en el listado de productos." << endl 
                    << "Por favor, revise que el id del producto que desea agregar sea correcto." << endl << endl;
            }

        } while (articleId != 0);
        
        //calculate total cost
        for (Article* article : articles)
        {
            totalCost += ( (article->getPrice()) * (article->getQuantity()) );
        }

        try
        {
            //create new id
            list<Order*> currentOrders = OrderManager::getOrders();

            id = currentOrders.empty() ?
            1
            :
            ((currentOrders.back())->getId()) + 1;

            //generate new order
            newOrder = new Order(id, *(client), articles, totalCost);

            //push it into orders list
            currentOrders.push_back(newOrder);

            //save it into manager class
            OrderManager::setOrders(currentOrders);

            cout << "¡Orden agregada correctamente, con id: " << newOrder->getId() << " !" << endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            cout << "¡No se ha podido crear la nueva orden por esta razon!";
            if(newOrder) delete newOrder;
        }

    }

    return newOrder;
};

bool OrderManager::cancelOrder(){};