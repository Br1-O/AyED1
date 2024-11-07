// Marco Practico

// Una Empresa que realiza Servicios de Limpieza de Tapizados “Beauty-Sand” nos convoca para la
// realización de una App que permita registrar los Pedidos de Embellecimiento de los Autos.
// En esta etapa del desarrollo, solo deberemos realizar el módulo “Solicitudes”
// La misma debe permitir:
// 1. Gestionar las Solicitudes
// a. Dar de alta la Solicitud (el código de la Solicitud es BT-500, BT-501… , se
// incrementa de a 1 con cada nuevo registro ). Campos: ID, Apellido y Nombre,
// Monto a pagar)
// b. Dar de Baja las Solicitudes x código de Solicitud (Ej: BT-504).
// c. Modificar las Solicitudes, ingresar el código, mostrarlo y editarlo.
// 2. Listar las solicitudes.
// a. Listar todas las Solicitudes.
// b. Buscar unas Solicitud x código (Ej: BT-501) y mostrarla (imprimir cartel de no
// encontrado).

// 3. Todo esto mediante un Menú, Modularizando en Funciones, utilizando Archivos, arreglos y
// estructuras.


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//■■■■■■■■■■■■ Custom types definitions ■■■■■■■■■■■■//

typedef struct
{
    string id;
    string name;
    string surname;
    double cost;
} tOrder;

const int maxNumberOrders = 200;
typedef tOrder tOrdersArray[maxNumberOrders];

typedef struct
{
    tOrdersArray ordersList;
    int totalActiveOrders;
} tOrdersList;

typedef ifstream readFile;
typedef ofstream writeFile;
typedef const string tPath;

//■■■■■■■■■■■■ Functions declaration ■■■■■■■■■■■■//

void showMenu();
// void haltConsole();
// void clearConsole();

void insertOrder(tOrdersList &ordersList);

tOrdersList getOrdersList(tPath path);
tOrder getOrderById(const tOrdersList ordersList, const string orderCode);
int getOrderIndexById(const tOrdersList ordersList, const string orderCode);

void displayOrdersList(const tOrdersList ordersList);
void displayOrder(const tOrder order);

bool updateOrder(tPath path, tOrdersList &ordersList, tOrder order, int field);

bool deleteOrder(tPath path, tOrdersList &ordersList, string orderCode);

bool saveOrdersListIntoFile(tPath path, const tOrdersList ordersList);

//■■■■■■■■■■■■ Main function ■■■■■■■■■■■■//

int main(int argc, char const *argv[])
{
    tPath ordersFilePath = "beauty_Sand_Orders_List.txt";
    tOrdersList ordersList = getOrdersList(ordersFilePath);

    int selectedOption;

    do
    {
        showMenu();

        cin >> selectedOption;

        switch (selectedOption)
        {
            case 1:
                insertOrder(ordersList);
                saveOrdersListIntoFile(ordersFilePath, ordersList);
                break;

            case 2:
            {
                string orderId;
                tOrder order;
                bool isValidOperation;

                cout << "Por favor, ingrese el id de la orden que desea modificar: ";
                cin >> orderId;

                order = getOrderById(ordersList, orderId);

                if (order.id != " ")
                {
                    cout << "Los datos actuales de la orden son: "<<endl;
                    displayOrder(order);

                    int selectedFieldToModify = 0;

                    cout << "--------------------------" << endl
                         << "Seleccione el campo a modificar: "<< endl
                         << "1. Nombre" << endl
                         << "2. Apellido" << endl
                         << "3. Costo" << endl
                         << "0. Cancelar" << endl
                         << "--------------------------" << endl
                         << endl;

                    cin >> selectedFieldToModify;

                    if (selectedFieldToModify > 0 && selectedFieldToModify <= 3)
                    {
                        isValidOperation = updateOrder(ordersFilePath, ordersList, order, selectedFieldToModify);
                    }
                    else
                    {
                        isValidOperation = false;
                    }

                    if (isValidOperation)
                    {
                        cout << "La orden ha sido modificada correctamente." <<endl;
                    }
                    else
                    {
                        cout << "La orden no ha sido modificada." <<endl;
                    }
                }
                else
                {
                    cout << "La orden no se ha podido encontrar para realizar la modificacion." <<endl;
                }
            }
            break;

            case 3:
            {
                string orderId;
                bool isValidOperation;

                cout << "Por favor, ingrese el id de la orden que desea borrar: ";
                cin >> orderId;

                isValidOperation = deleteOrder(ordersFilePath, ordersList, orderId);

                if (isValidOperation)
                {
                    cout << "La orden ha sido borrada correctamente de la lista." <<endl;
                }
                else
                {
                    cout << "La orden no se ha podido remover de la lista." <<endl;
                }
            }
            break;

            case 4:
                displayOrdersList(ordersList);
                break;

            case 5:
            {                
                string orderId;

                cout << "Por favor, ingrese el id de la orden que desea buscar: ";
                cin >> orderId;

                tOrder order = getOrderById(ordersList, orderId);

                if (order.id != " ")
                {
                    displayOrder(order);
                }
                else
                {
                    cout << "La orden no ha sido encontrada." << endl;
                }
            }
            break;
        }

    } while (selectedOption != 0);

    return 0;
}

//■■■■■■■■■■■■ Functions definition ■■■■■■■■■■■■//

//■■■■■■■■■■■■ Menu ■■■■■■■■■■■■//

void showMenu(){

    cout << "-------------- Beauty-Sandapp ------------" << endl
         << "1. Agregar una nueva orden" << endl
         << "2. Modificar una orden" << endl
         << "3. Borrar una orden" << endl
         << "4. Mostrar ordenes activas" << endl
         << "5. Buscar una orden" << endl
         << "0. Salir" << endl
         << "--------------------------" << endl
         << endl;
}

//■■■■■■■■■■■■ Read file into orders List ■■■■■■■■■■■■//

tOrdersList getOrdersList(tPath path){

    tOrdersList ordersList;
    ordersList.totalActiveOrders = 0;

    readFile ordersFile;
    ordersFile.open(path);

    if (ordersFile.is_open())
    {
        tOrder currentOrder;
        string currentOrderId;

        ordersFile >> currentOrderId;

        while (currentOrderId != "END_OF_FILE")
        {
            currentOrder.id = currentOrderId;

            ordersFile >> currentOrder.name;
            ordersFile >> currentOrder.surname;
            ordersFile >> currentOrder.cost;

            ordersList.ordersList[ordersList.totalActiveOrders] = currentOrder;
            ordersList.totalActiveOrders++;

            ordersFile >> currentOrderId;
        }

        ordersFile.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo de ordenes." << endl;
    }

    return ordersList;
}

//■■■■■■■■■■■■ Save updated orders List into file ■■■■■■■■■■■■//

bool saveOrdersListIntoFile(tPath path, tOrdersList ordersList){

    bool success = false;

    writeFile ordersFile;
    ordersFile.open(path);

    if (ordersFile.is_open())
    {
        for (size_t i = 0; i < ordersList.totalActiveOrders; i++)
        {
            ordersFile << (ordersList.ordersList[i]).id << " ";
            ordersFile << (ordersList.ordersList[i]).name << " ";
            ordersFile << (ordersList.ordersList[i]).surname << " ";
            ordersFile << (ordersList.ordersList[i]).cost << "\n";
        }

        ordersFile << "END_OF_FILE";

        ordersFile.close();
        success = true;
    }
    else
    {
        cout << "No se pudo abrir el archivo de ordenes." << endl;
    }

    return success;
};

//■■■■■■■■■■■■ Display orders list ■■■■■■■■■■■■//

void displayOrder(tOrder order){
    cout << "Id: " << order.id << endl;
    cout << "Nombre: " << order.name << endl;
    cout << "Apellido: " << order.surname << endl;
    cout << "Costo: " << order.cost << endl;
    cout << "--------------------------" << endl;
}

void displayOrdersList(tOrdersList ordersList){
    if (ordersList.totalActiveOrders == 0)
    {
        cout << "No hay ordenes activas actualmente." << endl;
    }
    else
    {
        cout << "El listado de ordenes activas es:" << endl;

        for (int i = 0; i < ordersList.totalActiveOrders; i++)
        {
            displayOrder(ordersList.ordersList[i]);
        }
    }
}

//■■■■■■■■■■■■ Insert new order ■■■■■■■■■■■■//

void insertOrder(tOrdersList &ordersList){

    if (maxNumberOrders <= ordersList.totalActiveOrders)
    {
        cout << "¡La lista esta llena! Por favor amplie la capacidad para insertar nuevos registros." << endl;
    }
    else
    {   
        tOrder order;
        string lastOrderId;

        //insertion of new order data
        cout << "Ingrese el nombre del cliente: ";
        cin.ignore();
        getline(cin, order.name);

        cout << "Ingrese el apellido del cliente: ";
        getline(cin, order.surname);

        cout << "Ingrese el costo de la solicitud: ";
        cin >> order.cost;

        if (ordersList.totalActiveOrders > 0)
        {
            lastOrderId = ordersList.ordersList[ordersList.totalActiveOrders - 1].id;

            order.id = "BT-" + to_string(stoi(lastOrderId.substr(3)) + 1);
        }
        else
        {
            order.id = "BT-500";
        }

        ordersList.ordersList[ordersList.totalActiveOrders] = order;
        ordersList.totalActiveOrders++;
    }
}

//■■■■■■■■■■■■ Search for client info ■■■■■■■■■■■■//

tOrder getOrderById(tOrdersList ordersList, const string orderCode){

    tOrder order;
    order.id = " ";

    for (int i = 0; i < ordersList.totalActiveOrders; i++)
    {
        if (ordersList.ordersList[i].id == orderCode)
        {
            order = ordersList.ordersList[i];
        }
    }

    return order;
}

int getOrderIndexById(tOrdersList ordersList, const string orderCode){
    int orderIndex = -1;

    for (int i = 0; i < ordersList.totalActiveOrders; i++)
    {
        if (ordersList.ordersList[i].id == orderCode)
        {
            orderIndex = i;
        }
    }

    return orderIndex;
}

//■■■■■■■■■■■■ Update order by Id ■■■■■■■■■■■■//

bool updateOrder(tPath path, tOrdersList &ordersList, tOrder order, int field){

    bool success = false;
    string id = order.id;

    int orderIndex = getOrderIndexById(ordersList, id);

    tOrder *orderToModify = &ordersList.ordersList[orderIndex];

    switch (field)
    {
    case 1:
        cout << "Ingrese el nuevo nombre del cliente: ";
        cin.ignore();
        getline(cin, orderToModify->name);
        break;

    case 2:
        cout << "Ingrese el nuevo apellido del cliente: ";
        cin.ignore();
        getline(cin, orderToModify->surname);
        break;

    case 3:
        cout << "Ingrese el nuevo costo de la solicitud: ";
        cin >> orderToModify->cost;
        break;
    }

    success = saveOrdersListIntoFile(path, ordersList);

    return success;
}

//■■■■■■■■■■■■ Delete order by Id ■■■■■■■■■■■■//

bool deleteOrder(tPath path, tOrdersList &ordersList, string orderCode){

    int orderIndex = getOrderIndexById(ordersList, orderCode);
    bool isValidOperation = false;

    if (orderIndex >= 0)
    {
        for (int i = orderIndex; i < ordersList.totalActiveOrders - 1; i++)
        {
            ordersList.ordersList[i] = ordersList.ordersList[i + 1];
        }

        ordersList.totalActiveOrders--;

        isValidOperation = saveOrdersListIntoFile(path, ordersList);
    }

    return isValidOperation;
}

//■■■■■■■■■■■■ Utils functions ■■■■■■■■■■■■//

// void haltConsole() 
// {
//     std::cout << "Presione Enter para continuar..." << std::endl;
//     std::cin.ignore();
//     std::cin.get();
// }

// void clearConsole() 
// {
//     #ifdef __unix__
//         system("clear");
//     #elif __APPLE__
//         system("clear");
//     #elif defined(_WIN32) || defined(WIN32) || defined(WIN64)
//         system("cls");
//     #endif
// }
