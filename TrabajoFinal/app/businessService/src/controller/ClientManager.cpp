#include <iostream>
#include <list>
#include <string>

#include "../../include/controller/ClientManager.hpp"
#include "../../include/model/Client.hpp"
#include "../../../utils/include/Utils.hpp"

using namespace std;

//■■■■■■■■■ getters ■■■■■■■■■//

//client
std::list<Client*> ClientManager::getClients() const{
    return this-> clients;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//client
void ClientManager::setNewClients(Client* client){
    (this->clients).push_back(client);
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

    //since my Manager classes are singletons, which are suppose to live through the whole app lifetime they don't implement a default destructor

};

//■■■■■■■■■ methods ■■■■■■■■■//

void ClientManager::displayClientList(){
    
    list<Client*> currentClients = ClientManager::defaultClientManager.getClients();

    string title = "Listado de clientes: ";
    string lineSeparator =  "---------------------------------";

    cout << title << endl;

    for (const auto& client:currentClients)
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
}

Client ClientManager::getClientById(int id) {

    Client foundClient;
    foundClient.setId(0);

    const auto& currentClients = ClientManager::defaultClientManager.getClients();

    for (const auto& client : currentClients) {
        if (id == client->getId()) {
            foundClient = *client;
        }
    }

    return foundClient;
}

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
        list<Client*> currentClients = ClientManager::defaultClientManager.getClients();

        id = currentClients.empty() ?
        1
        :
        ((currentClients.back())->getId()) + 1;

        //generate new client
        newClient = new Client(id, name, lastName, phone, address);

        //save it into manager class
        ClientManager::defaultClientManager.setNewClients(newClient);

        cout << endl << "Cliente agregado correctamente." << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "No se ha podido crear el nuevo cliente por esta razon.";
        if(newClient) delete newClient;
    }

    return newClient;
};

//■■■■■■■■■ default instance ■■■■■■■■■//

ClientManager ClientManager::defaultClientManager;