#include <iostream>
#include <list>
#include <string>

#include "../../include/ClientManager.hpp"
#include "../../include/Client.hpp"
#include "../../include/Utils.hpp"

using namespace std;

//■■■■■■■■■ getters ■■■■■■■■■//

//client
std::list<Client*> ClientManager::getClients(){
    return this-> clients;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//client
void ClientManager::setClients(std::list<Client*> clients){
    this->clients = clients;
};

//■■■■■■■■■ constructor ■■■■■■■■■//

ClientManager::ClientManager(){};

ClientManager::ClientManager(            
    std::list<Client*> clients
){
    this->clients = clients;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

ClientManager::~ClientManager(){

    for (Client* client: ClientManager::clients)
    {
        delete client;
    }
    clients.clear();
};

//■■■■■■■■■ methods ■■■■■■■■■//

void ClientManager::displayClientList(){
    
    list<Client*> currentClients = ClientManager::getClients();

    string title = "Listado de clientes: ";
    string lineSeparator =  "---------------------------------";

    cout << title << endl;

    for (Client* client:currentClients)
    {
        cout << lineSeparator << endl;
        cout << "Id: " << client->getId() << endl;
        cout << "Nombre: " << client->getName() << endl;
        cout << "Apellido: " << client->getLastName() << endl;
        cout << "Telefono: " << client->getPhone() << endl;
        cout << "Direccion: " << client->getAddress() << endl;
        cout << lineSeparator << endl;
    }

    cout << endl;

    utils::pauseConsole();
}

Client* ClientManager::getClientById(int id){

    Client* searchedClient = nullptr;

    list<Client*> currentClients = ClientManager::getClients();

    for (Client* client : currentClients)
    {
        if (id == (client->getId()))
        {
            searchedClient = client;
            break;
        }
    }

    return searchedClient;
};

Client* ClientManager::loadNewClient(){

    int id;
    std::string name, lastName, phone, address;

    Client* newClient = nullptr;

    cout << "Por favor, ingrese el nombre del nuevo cliente: " << endl;
    getline(cin, name);

    cout << "Por favor, ingrese el apellido del nuevo cliente: " << endl;
    getline(cin, lastName);

    cout << "Ingrese el telefono del nuevo cliente: " << endl;
    getline(cin, phone);

    cout << "Ingrese la direccion del nuevo cliente: " << endl;
    getline(cin, address);

    try
    {
        //create new id
        list<Client*> currentClients = ClientManager::getClients();

        id = currentClients.empty() ?
        1
        :
        ((currentClients.back())->getId()) + 1;

        //generate new client
        newClient = new Client(id, name, lastName, phone, address);

        //push it into clients list
        currentClients.push_back(newClient);

        //save it into manager class
        ClientManager::setClients(currentClients);

        cout << "¡Cliente agregado correctamente!" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "¡No se ha podido crear el nuevo cliente por esta razon!";
        if(newClient) delete newClient;
    }

    return newClient;
};