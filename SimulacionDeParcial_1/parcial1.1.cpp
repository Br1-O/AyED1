//Consigna:

// Una Empresa que vende “productos de seguridad industrial NicTech” nos convoca para la realización de una
// App que permita registrar los Pedidos de Artículos de los clientes.
// En esta etapa del desarrollo, solo deberemos realizar el módulo “Clientes”
// La misma debe permitir:
// 1. Gestionar los Clientes
// a. Dar de alta el cliente (el código del cliente se obtiene sumando 100 al índice del Array).
// b. Dar de Baja los clientes x código de cliente.
// c. Modificar los clientes, ingresar el código, mostrarlo y editarlo.
// 2. Listar los Clientes.
// a. Listar todos los Clientes.
// b. Buscar un Clientes x código y mostrarlo (imprimir cartel de no encontrado).
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
    string code;
    string name;
    string surname;
    int dni;
} tClient;

const int maxNumberClients = 20;
typedef tClient tClientsArray[maxNumberClients];

typedef struct
{
    tClientsArray clientsList;
    int totalActiveClients;
} tClientsList;

typedef ifstream readFile;
typedef ofstream writeFile;
typedef const string tPath;

//■■■■■■■■■■■■ Functions declaration ■■■■■■■■■■■■//

void showMenu();
void haltConsole();
void clearConsole();
void handleSelectedOption(int &selectedOption, tPath clientsFilePath, tClientsList &clientsList);

void insertClient(tClientsList &clientsList);

tClientsList getClientsList(tPath path);
tClient getClientByCode(const tClientsList clientsList, const string clientCode);
int getClientIndexByCode(const tClientsList clientsList, const string clientCode);

void displayClientsList(const tClientsList clientsList);
void displayClient(const tClient client);

bool updateClient(tPath path, tClientsList &clientsList, tClient client, int field);

bool deleteClient(tPath path, tClientsList &clientsList, string clientCode);

bool saveClientsListIntoFile(tPath path, const tClientsList clientsList);

//■■■■■■■■■■■■ Main function ■■■■■■■■■■■■//

int main(int argc, char const *argv[])
{
    tPath clientsFilePath = "nichSecurityClientsList.txt";
    tClientsList clientsList = getClientsList(clientsFilePath);

    int selectedOption;

    do
    {
        showMenu();
        handleSelectedOption(selectedOption, clientsFilePath, clientsList);

        if (selectedOption != 0)
        {
            haltConsole();
            clearConsole();
        }

    } while (selectedOption != 0);

    return 0;
}

//■■■■■■■■■■■■ Functions definition ■■■■■■■■■■■■//

//■■■■■■■■■■■■ Utils functions ■■■■■■■■■■■■//

void haltConsole() 
{
    cout << endl << "Presione Enter para volver al menu..." << endl;
    cin.sync();
    cin.get();
}

void clearConsole() 
{
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN32) || defined(WIN64)
        system("cls");
    #endif
}

void intInputValidation(int &num, string message, string errorMessage)
{

    bool error = true;

   do{
        cout << message;
        cin >> num;
        cin.sync();
        cout << endl << endl;

        if (cin.fail())
        {
            cout << errorMessage << endl << endl;
            cin.clear();
            cin.sync();
        }
        else
        {
            error = false;
        }
   }
   while(error);
}

//■■■■■■■■■■■■ Menu ■■■■■■■■■■■■//

void showMenu(){

    cout << "--------------------------" << endl
         << "1. Agregar cliente" << endl
         << "2. Modificar Cliente" << endl
         << "3. Borrar Cliente" << endl
         << "4. Mostrar Clientes" << endl
         << "5. Buscar un Cliente" << endl
         << "0. Salir" << endl
         << "--------------------------" << endl
         << endl;
}

void handleSelectedOption(int &selectedOption, tPath clientsFilePath, tClientsList &clientsList){

    cin >> selectedOption;
    cin.sync();
    clearConsole();

    switch (selectedOption)
    {
        case 1:
            insertClient(clientsList);
            saveClientsListIntoFile(clientsFilePath, clientsList);
        break;

        case 2:
            {
                string clientCode;
                tClient client;
                bool isValidOperation;

                cout << "Por favor, ingrese el codigo del cliente que desea modificar: ";
                cin >> clientCode;
                cin.sync();

                client = getClientByCode(clientsList, clientCode);

                if (client.code != " ")
                {
                    cout << "Los datos actuales del cliente son: "<<endl;
                    displayClient(client);

                    int selectedFieldToModify = 0;
        
                    cout << "--------------------------" << endl
                    << "Seleccione el campo a modificar: "<< endl
                    << "1. Nombre" << endl
                    << "2. Apellido" << endl
                    << "3. DNI" << endl
                    << "0. Cancelar" << endl
                    << "--------------------------" << endl
                    << endl;

                    cin >> selectedFieldToModify;
                    cin.sync();

                    switch (selectedFieldToModify)
                    {
                        case 1:
                            isValidOperation = updateClient(clientsFilePath, clientsList, client, selectedFieldToModify);
                        break;

                        case 2:
                            isValidOperation = updateClient(clientsFilePath, clientsList, client, selectedFieldToModify);
                        break;
                        
                        case 3:
                            isValidOperation = updateClient(clientsFilePath, clientsList, client, selectedFieldToModify);
                        break;
                        
                        default:
                            isValidOperation = false;
                        break;
                    }

                    if (isValidOperation)
                    {
                        cout << "El cliente ha sido modificado correctamente." <<endl;
                    }
                    else
                    {
                        cout << "El cliente no ha sido modificado." <<endl;
                    }
                }
                else
                {
                    cout << "El cliente no se ha podido encontrar para realizar la modificacion." <<endl;
                }
                
            }
        break;

        case 3:
            {
                string clientCode;
                bool isValidOperation;

                cout << "Por favor, ingrese el codigo del cliente que desea borrar: ";
                cin >> clientCode;
                cin.sync();

                isValidOperation = deleteClient(clientsFilePath, clientsList, clientCode);

                if (isValidOperation)
                {
                    cout << "El cliente ha sido borrado correctamente de la lista." <<endl;
                }
                else
                {
                    cout << "El cliente no se ha podido remover de la lista." <<endl;
                }
            }
        break;

        case 4:
            displayClientsList(clientsList);
        break;

        case 5:
            {                
                string clientCode;

                cout << "Por favor, ingrese el codigo del cliente que desea buscar: ";
                cin >> clientCode;
                cin.sync();

                tClient client = getClientByCode(clientsList, clientCode);

                if (client.code != " ")
                {
                    displayClient(client);
                }
                else
                {
                    cout << "El cliente no ha sido encontrado." << endl;
                }
            }
        break;
    }
}

//■■■■■■■■■■■■ Read file into clients List ■■■■■■■■■■■■//

tClientsList getClientsList(tPath path){

    tClientsList clientsList;
    clientsList.totalActiveClients = 0;

    readFile clientsFile;
    clientsFile.open(path);

    if (clientsFile.is_open())
    {
        tClient currentClient;
        string currentClientCode;

        clientsFile >> currentClientCode;

        while (currentClientCode != "END_OF_FILE")
        {
            currentClient.code = currentClientCode;

            clientsFile >> currentClient.name;
            clientsFile >> currentClient.surname;
            clientsFile >> currentClient.dni;

            clientsList.clientsList[clientsList.totalActiveClients] = currentClient;
            clientsList.totalActiveClients++;

            clientsFile >> currentClientCode;
        }

        clientsFile.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo de clientes." << endl;
    }

    return clientsList;
}

//■■■■■■■■■■■■ Save updated clients List into file ■■■■■■■■■■■■//

bool saveClientsListIntoFile(tPath path, tClientsList clientsList){

    bool success = false;

    writeFile clientsFile;
    clientsFile.open(path);

    if (clientsFile.is_open())
    {
        for (size_t i = 0; i < clientsList.totalActiveClients; i++)
        {
            clientsFile << (clientsList.clientsList[i]).code << " ";
            clientsFile << (clientsList.clientsList[i]).name << " ";
            clientsFile << (clientsList.clientsList[i]).surname << " ";
            clientsFile << (clientsList.clientsList[i]).dni << "\n";
        }

        clientsFile << "END_OF_FILE";

        clientsFile.close();
        success = true;
    }
    else
    {
        cout << "No se pudo abrir el archivo de clientes." << endl;
    }
    
    return success;
};

//■■■■■■■■■■■■ Display clients list ■■■■■■■■■■■■//

void displayClient(tClient client){
    cout << "Codigo: " << client.code << endl;
    cout << "Nombre: " << client.name << endl;
    cout << "Apellido: " << client.surname << endl;
    cout << "DNI: " << client.dni << endl;
    cout << "--------------------------" << endl;
}

void displayClientsList(tClientsList clientsList){
    if (clientsList.totalActiveClients == 0)
    {
        cout << "No hay clientes activos actualmente." << endl;
    }
    else
    {
        cout << "El listado de clientes activos es:" << endl;

        for (int i = 0; i < clientsList.totalActiveClients; i++)
        {
            displayClient(clientsList.clientsList[i]);
        }
    }
}

//■■■■■■■■■■■■ Insert new client ■■■■■■■■■■■■//

void insertClient(tClientsList &clientsList){

    if (maxNumberClients <= clientsList.totalActiveClients)
    {
        cout << "¡La lista esta llena! Por favor amplie la capacidad para insertar nuevos registros." << endl;
    }
    else
    {   
        tClient client;
        string lastClientCode;

        //insertion of new Client data
        cout << "Ingrese el nombre del cliente: ";
        cin.ignore();
        getline(cin, client.name);
        cin.sync();
        
        cout << "Ingrese el apellido del cliente: ";
        getline(cin, client.surname);
        cin.sync();

        cout << "Ingrese el dni del cliente: ";
        cin >> client.dni;
        cin.sync();

        if (clientsList.totalActiveClients > 0)
        {
            lastClientCode = clientsList.clientsList[clientsList.totalActiveClients - 1].code;

            client.code = "C" + to_string(stoi(lastClientCode.substr(1)) + 1);
        }
        else
        {
            client.code = "C100";
        }

        clientsList.clientsList[clientsList.totalActiveClients] = client;
        clientsList.totalActiveClients++;
    }
}

//■■■■■■■■■■■■ Search for client info ■■■■■■■■■■■■//

tClient getClientByCode(tClientsList clientList, string clientCode){

    bool found = false;
    tClient client = {" ", " ", " ", 0};

    if (clientList.totalActiveClients == 0 )
    {
        cout << "No hay clientes activos que coincidan con ese cliente." <<endl;
    }
    else
    {
        int i = 0;

        do{
            if (clientList.clientsList[i].code == clientCode)
            {
                client = clientList.clientsList[i];
                found = true;
            }

            i++;

        }while ((found == false) && (i < clientList.totalActiveClients));
    }

    return client;
};

int getClientIndexByCode(tClientsList clientList, string clientCode){
    bool found = false;
    int index = -1;

    if (clientList.totalActiveClients != 0 )
    {
        int i = 0;

        do{
            if (clientList.clientsList[i].code == clientCode)
            {
                index = i;
                found = true;
            }

            i++;

        }while ((found == false) && (i < clientList.totalActiveClients));
    }

    return index;
}

//■■■■■■■■■■■■ Delete client ■■■■■■■■■■■■//

bool deleteClient(tPath clientsFilePath, tClientsList &clientsList, string clientCode){

    bool success = false;

    int index = getClientIndexByCode(clientsList, clientCode);

    if (index != (-1))
    {
        for (size_t i = index; i < clientsList.totalActiveClients; i++)
        {
            clientsList.clientsList[i] = clientsList.clientsList[i + 1];
        }

        clientsList.totalActiveClients--;

        success = saveClientsListIntoFile(clientsFilePath, clientsList);
    }

    return success;
}

//■■■■■■■■■■■■ Update client ■■■■■■■■■■■■//

bool updateClient(tPath clientsFilePath, tClientsList &clientsList, tClient client, int field){

    bool success = false;

    int index = getClientIndexByCode(clientsList, client.code);

    switch (field)
    {
        case 1:
        {
            string name;

            cout << "Por favor ingrese el nombre para el cliente: ";
            cin >> name;
            cin.sync();

            client.name = name;

            clientsList.clientsList[index] = client;

            success = saveClientsListIntoFile(clientsFilePath, clientsList);
        }
        break;

        case 2:
        {
            string surname;

            cout << "Por favor ingrese el apellido para el cliente: ";
            cin >> surname;
            cin.sync();

            client.surname = surname;

            clientsList.clientsList[index] = client;

            success = saveClientsListIntoFile(clientsFilePath, clientsList);
        }
        break;

        case 3:
        {
            int dni;

            cout << "Por favor ingrese el DNI para el cliente: ";
            cin >> dni;
            cin.sync();

            client.dni = dni;

            clientsList.clientsList[index] = client;

            success = saveClientsListIntoFile(clientsFilePath, clientsList);
        }
        break;
    
    }

    return success;
};