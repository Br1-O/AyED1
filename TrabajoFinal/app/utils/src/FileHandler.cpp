#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "../../businessService/include/model/Client.hpp"
#include "../../businessService/include/model/Article.hpp"
#include "../../businessService/include/model/Employee.hpp"
#include "../../businessService/include/model/Order.hpp"
#include "../../businessService/include/controller/ArticleManager.hpp"
#include "../../businessService/include/controller/ClientManager.hpp"
#include "../../businessService/include/controller/EmployeeManager.hpp"
#include "../../businessService/include/controller/OrderManager.hpp"
#include "../include/FileHandler.hpp"
#include "../include/Utils.hpp"

using namespace std;

//■■■■■■■■■ getters ■■■■■■■■■//

//file path
string FileHandler::getFilePath() const{
    return this->filePath;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//orders
void FileHandler::setFilePath(string filePath){
    this->filePath = filePath;
};

//■■■■■■■■■ constructor ■■■■■■■■■//

FileHandler::FileHandler(){};

FileHandler::FileHandler(string filePath){
    this->filePath = filePath;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

FileHandler::~FileHandler(){};

//■■■■■■■■■ methods ■■■■■■■■■//

bool FileHandler::loadDataFromFile(string filePath, ClientManager* clientManagerInstance, ArticleManager* articleManagerInstance, EmployeeManager* employeeManagerInstance, OrderManager* orderManagerInstance)
{
    this->setFilePath(filePath);

    bool isCorrectLoaded = false;

    (this->readFile).open(this->filePath);

    if ((this->readFile).is_open())
    {
        
        string tempLine;
        string currentTable;

        while(getline(this->readFile, tempLine))
        {
            size_t pos = 0;
            size_t commaPos = 0;

            //skip empty lines
            if (tempLine.empty()) {
                continue;
            }

            //check if this line is a table name
            if (tempLine == "Articles" || tempLine == "Clients" || tempLine == "Employees" || tempLine == "Orders") {
                currentTable = tempLine;  //update the current section
                continue;
            }

            //■■■ Articles table parsing ■■■//
            if (currentTable == "Articles")
            {
                Article* currentArticle = new Article();

                //get id
                commaPos = tempLine.find(',', pos); //check the position of the next comma, which ends
                if (commaPos != std::string::npos) {
                    currentArticle->setId(std::stoi(tempLine.substr(pos, commaPos - pos)));
                    pos = commaPos + 1;
                }

                //get name
                commaPos = tempLine.find(',', pos); 
                if (commaPos != std::string::npos) {
                    currentArticle->setName(tempLine.substr(pos + 1, commaPos - pos - 2)); //ignore the "" chars
                    pos = commaPos + 1;
                }

                //get price
                commaPos = tempLine.find(',', pos);
                if (commaPos != std::string::npos) {
                    currentArticle->setPrice(std::stod(tempLine.substr(pos, commaPos - pos)));
                    pos = commaPos + 1;
                }

                //units in stock
                commaPos = tempLine.find(',', pos);
                if (commaPos != std::string::npos) {
                    currentArticle->setUnitsInStock(std::stoi(tempLine.substr(pos, commaPos - pos)));
                    pos = commaPos + 1;
                }

                //save the current article into the article manager instance's list
                articleManagerInstance->setNewArticles(currentArticle);

            }
            //■■■ Clients table parsing ■■■//
            else if (currentTable == "Clients")
            {
                Client* currentClient = new Client();

                //get id
                commaPos = tempLine.find(',', pos); //check the position of the next comma, which ends
                if (commaPos != std::string::npos) {
                    currentClient->setId(std::stoi(tempLine.substr(pos, commaPos - pos)));
                    pos = commaPos + 1;
                }

                //get name
                commaPos = tempLine.find(',', pos); 
                if (commaPos != std::string::npos) {
                    currentClient->setName(tempLine.substr(pos + 1, commaPos - pos - 2)); //ignore the "" chars
                    pos = commaPos + 1;
                }

                //get last name
                commaPos = tempLine.find(',', pos); 
                if (commaPos != std::string::npos) {
                    currentClient->setLastName(tempLine.substr(pos + 1, commaPos - pos - 2)); //ignore the "" chars
                    pos = commaPos + 1;
                }

                //get phone
                commaPos = tempLine.find(',', pos); 
                if (commaPos != std::string::npos) {
                    currentClient->setPhone(tempLine.substr(pos + 1, commaPos - pos - 2)); //ignore the "" chars
                    pos = commaPos + 1;
                }

                //get address
                commaPos = tempLine.find(',', pos); 
                if (commaPos != std::string::npos) {
                    currentClient->setAddress(tempLine.substr(pos + 1, commaPos - pos - 2)); //ignore the "" chars
                    pos = commaPos + 1;
                }

                //save the current client into the client manager instance's list
                clientManagerInstance->setNewClients(currentClient);
            }
            //■■■ Employees table parsing ■■■//
            else if(currentTable == "Employees")
            {
                Employee* currentEmployee = new Employee();

                //get id
                commaPos = tempLine.find(',', pos); //check the position of the next comma, which ends
                if (commaPos != std::string::npos) {
                    currentEmployee->setId(std::stoi(tempLine.substr(pos, commaPos - pos)));
                    pos = commaPos + 1;
                }

                //get name
                commaPos = tempLine.find(',', pos); 
                if (commaPos != std::string::npos) {
                    currentEmployee->setFirstName(tempLine.substr(pos + 1, commaPos - pos - 2)); //ignore the "" chars
                    pos = commaPos + 1;
                }

                //get last name
                commaPos = tempLine.find(',', pos); 
                if (commaPos != std::string::npos) {
                    currentEmployee->setLastName(tempLine.substr(pos + 1, commaPos - pos - 2)); //ignore the "" chars
                    pos = commaPos + 1;
                }

                //get position
                commaPos = tempLine.find(',', pos); 
                if (commaPos != std::string::npos) {
                    currentEmployee->setPosition(tempLine.substr(pos + 1, commaPos - pos - 2)); //ignore the "" chars
                    pos = commaPos + 1;
                }

                //get salary
                commaPos = tempLine.find(',', pos);
                if (commaPos != std::string::npos) {
                    currentEmployee->setSalary(std::stod(tempLine.substr(pos, commaPos - pos)));
                    pos = commaPos + 1;
                }

                //save the current employee into the employee manager instance's list
                employeeManagerInstance->setNewEmployee(currentEmployee);
            }        
            //■■■ Orders table parsing ■■■//
            else if(currentTable == "Orders")
            {
                Order* currentOrder = new Order();

                //get id
                commaPos = tempLine.find(',', pos); //check the position of the next comma, which ends
                if (commaPos != std::string::npos) {
                    currentOrder->setId(std::stoi(tempLine.substr(pos, commaPos - pos)));
                    pos = commaPos + 1;
                }

                //get client id in order
                commaPos = tempLine.find(',', pos); //check the position of the next comma, which ends
                if (commaPos != std::string::npos) {
                    //search for the client's data via the saved id
                    const Client client = clientManagerInstance->defaultClientManager.getClientById(std::stoi(tempLine.substr(pos, commaPos - pos)));
                    currentOrder->setClient(client);
                    pos = commaPos + 1;
                }

                //get employee id in order
                commaPos = tempLine.find(',', pos); //check the position of the next comma, which ends
                if (commaPos != std::string::npos) {
                    //search for the employee's data via the saved id
                    const Employee employee = employeeManagerInstance->defaultEmployeeManager.getEmployeeById(std::stoi(tempLine.substr(pos, commaPos - pos)));
                    currentOrder->setEmployee(employee);
                    pos = commaPos + 1;
                }

                //list for Articles inside order
                list<Article> articles;
                //article for articles of list
                Article currentArticle;

                while (pos < tempLine.length())
                {
                    //get article id
                    commaPos = tempLine.find(',', pos); //check the position of the next comma, which ends
                    if (commaPos != std::string::npos) {
                        currentArticle.setId(std::stoi(tempLine.substr(pos, commaPos - pos)));
                        pos = commaPos + 1;
                    }

                    //get article name
                    commaPos = tempLine.find(',', pos); 
                    if (commaPos != std::string::npos) {
                        currentArticle.setName(tempLine.substr(pos + 1, commaPos - pos - 2)); //ignore the "" chars
                        pos = commaPos + 1;
                    }

                    //get article price
                    commaPos = tempLine.find(',', pos);
                    if (commaPos != std::string::npos) {
                        currentArticle.setPrice(std::stod(tempLine.substr(pos, commaPos - pos)));
                        pos = commaPos + 1;
                    }

                    //get quantity of each article in the order
                    commaPos = tempLine.find(',', pos);
                    if (commaPos != std::string::npos) {
                        currentArticle.setQuantity(std::stoi(tempLine.substr(pos, commaPos - pos)));
                        pos = commaPos + 1;
                    }

                    //add article to the article list
                    articles.push_back(currentArticle);
                }

                //add list of articles into the list of articles inside the order
                currentOrder->setArticles(articles);

                //get total cost of the order
                double totalCost = 0.0;

                for (const auto& article : articles) {
                    totalCost += article.getPrice() * article.getQuantity();
                }

                //set total cost of the order
                currentOrder->setTotalCost(totalCost);

                //push order into orders list inside defaultManagerInstance
                orderManagerInstance->setNewOrders(currentOrder);
            }
        }

        (this->readFile).close();

        isCorrectLoaded = true;

        cout << endl  << "Datos cargados correctamente" << endl << endl;
    }
    else
    {
        bool createFile = false;
        string userOption = "no";

        cout << endl << "No se ha encontrado el archivo de datos. Desea crear el archivo?" << endl 
             << "AL CREAR EL ARCHIVO SE BORRARA POR COMPLETO EL ARCHIVO ANTERIOR Y LOS DATOS SE PERDERAN" << endl
             << "SELECCIONAR SOLO SI SE ESTA SEGURO QUE NO EXISTE" << endl
             << "Ingrese 'NUEVO' si desea crearlo, de lo contrario ingrese cualquier otra tecla para detener la ejecucion del programa: " << endl << endl;

        cin >> userOption;
        cin.ignore();

        if(userOption == "NUEVO" || userOption == "nuevo" || userOption == "Nuevo"){

            (this->writeFile).open(this->filePath);

            if((this->writeFile).is_open()){

                cout << "Nuevo archivo de datos creado." << endl << endl;

                (this->writeFile).close();

                utils::pauseConsole();

                isCorrectLoaded = true;

            }else{

                cout << "No se ha podido crear el nuevo archivo de datos." << endl << endl;

                utils::pauseConsole("Presione una tecla para continuar.");
            }

        }
    }

    return isCorrectLoaded;
};

bool FileHandler::saveDataIntoFile(string filePath, ClientManager clientManagerInstance, ArticleManager articleManagerInstance, EmployeeManager EmployeeManagerInstance, OrderManager OrderManagerInstance)
{
    const list<Article*> currentArticles = articleManagerInstance.getArticles();
    const list<Client*> currentClients = clientManagerInstance.getClients();
    const list<Employee*> currentEmployees = EmployeeManagerInstance.getEmployees();
    const list<Order*> activeOrders = OrderManagerInstance.getOrders();

    bool isCorrectSaved = false;

    string tableName;

    this->setFilePath(filePath);

    (this->writeFile).open(this->filePath);

    if ((this->writeFile).is_open())
    {

        tableName = "Articles";

        (this->writeFile) << tableName << endl;

        for (auto &&article: currentArticles)
        {
            (this->writeFile) << article->getId() << ","
                              << "\"" << article->getName() << "\","
                              << article->getPrice() << ","
                              << article->getUnitsInStock() << "," << endl;

        }

        tableName = "Clients";

        (this->writeFile) << tableName << endl;

        for (auto &&client: currentClients)
        {
            (this->writeFile) << client->getId() << ","
                              << "\"" << client->getName() << "\","
                              << "\"" << client->getLastName() << "\","
                              << "\"" << client->getPhone() << "\","
                              << "\"" << client->getAddress() << "\"," << endl;
        }

        tableName = "Employees";

        (this->writeFile) << tableName << endl;

        for (auto &&employee: currentEmployees)
        {
            (this->writeFile) << employee->getId() << ","
                              << "\"" << employee->getFirstName() << "\","
                              << "\"" << employee->getLastName() << "\","
                              << "\"" << employee->getPosition() << "\","
                              << employee->getSalary() << "," << endl;
        }

        tableName = "Orders";

        (this->writeFile) << tableName << endl;

        for (auto &&order: activeOrders)
        {
            (this->writeFile) << order->getId() << ","
                              << (order->getClient()).getId() << ","
                              << (order->getEmployee()).getId() << ",";

            for (auto &&article : (order->getArticles()))
            {
                (this->writeFile) << article.getId() << ","
                                  << "\"" << article.getName() << "\","
                                  << article.getPrice() << ","
                                  << article.getQuantity()  << ",";
            }

            (this->writeFile) << endl;
        }

        (this->writeFile).close();

        isCorrectSaved = true;
    }
    else
    {
        bool createFile = false;
        string userOption = "no";

        cout << "No se ha encontrado el archivo de datos. Desea crear el archivo?" << endl 
             << "AL CREAR EL ARCHIVO SE BORRARA POR COMPLETO EL ARCHIVO ANTERIOR Y LOS DATOS SE PERDERAN" << endl
             << "SELECCIONAR SOLO SI SE ESTA SEGURO QUE NO EXISTE!" << endl
             << "Ingrese 'NUEVO' si desea crearlo, de lo contrario ingrese cualquier otra tecla para detener la ejecucion del programa: " << endl << endl;

        cin >> userOption;
        cin.ignore();

        if(userOption == "NUEVO" || userOption == "nuevo" || userOption == "Nuevo"){

            (this->writeFile).open(this->filePath);

            if((this->writeFile).is_open()){

                cout << "Nuevo archivo de datos creado." << endl << endl;

                tableName = "Articles";

                (this->writeFile) << tableName << endl;

                for (auto &&article: currentArticles)
                {
                    (this->writeFile) << article->getId() << ","
                                    << "\"" << article->getName() << "\","
                                    << article->getPrice() << ","
                                    << article->getUnitsInStock() << "," << endl;
                }

                tableName = "Clients";

                (this->writeFile) << tableName << endl;

                for (auto &&client: currentClients)
                {
                    (this->writeFile) << client->getId() << ","
                                    << "\"" << client->getName() << "\","
                                    << "\"" << client->getLastName() << "\","
                                    << "\"" << client->getPhone() << "\","
                                    << "\"" << client->getAddress() << "\"," << endl;
                }

                tableName = "Employees";

                (this->writeFile) << tableName << endl;

                for (auto &&employee: currentEmployees)
                {
                    (this->writeFile) << employee->getId() << ","
                                    << "\"" << employee->getFirstName() << "\","
                                    << "\"" << employee->getLastName() << "\","
                                    << "\"" << employee->getPosition() << "\","
                                    << employee->getSalary() << "," << endl;
                }

                tableName = "Orders";

                (this->writeFile) << tableName << endl;

                for (auto &&order: activeOrders)
                {
                    (this->writeFile) << order->getId() << ","
                                    << (order->getClient()).getId() << ","
                                    << (order->getEmployee()).getId() << ",";

                    for (auto &&article : (order->getArticles()))
                    {
                        (this->writeFile) << article.getId() << ","
                                        << "\"" << article.getName() << "\","
                                        << article.getPrice() << ","
                                        << article.getQuantity()  << ",";
                    }

                    (this->writeFile) << endl;
                }

                (this->writeFile).close();

                utils::pauseConsole();

                isCorrectSaved = true;

            }else{

                cout << "No se ha podido crear el nuevo archivo de datos!" << endl << endl;

                utils::pauseConsole();
            }
        }
    }

    return isCorrectSaved;

};

//■■■■■■■■■ default instance ■■■■■■■■■//

FileHandler FileHandler::defaultFileHandler;