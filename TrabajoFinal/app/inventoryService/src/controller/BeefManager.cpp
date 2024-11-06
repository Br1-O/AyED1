#include <iostream>
#include <string>
#include <list>
#include "../../include/model/Beef.hpp"
#include "../../include/controller/BeefManager.hpp"
#include "../../../utils/include/Utils.hpp"
#include "../../../utils/include/Date.hpp" // Importing Date class

using namespace std;

//■■■■■■■■■ getters ■■■■■■■■■//

//beef articles
list<Beef*> BeefManager::getInventory() const{
    return this->inventory;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//beef articles
void BeefManager::setNewItem(Beef* beefCut){
    (this->inventory).push_back(beefCut);
};

//■■■■■■■■■ constructor ■■■■■■■■■//

BeefManager::BeefManager(){};

BeefManager::BeefManager(list<Beef*> inventory){
    this->inventory = inventory;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

BeefManager::~BeefManager(){

    //since my Manager classes are singletons, which are suppose to live through the whole app lifetime they don't implement a default destructor

};

//■■■■■■■■■ methods ■■■■■■■■■//

void BeefManager::displayInventoryList() const {

    list<Beef*> currentBeefInventory = BeefManager::defaultBeefManager.getInventory();

    string title = "Listado de inventario de carne vacuna: ";
    string lineSeparator =  "---------------------------------";

    cout << title << endl;

    for (const auto &beefCut :currentBeefInventory)
    {
        cout << lineSeparator << endl;
        
        beefCut->displayInfo();

        cout << lineSeparator << endl;
    }

    cout << endl;
};

Beef BeefManager::getItemById(int id) {
    Beef foundBeefCut;
    foundBeefCut.setId(0);

    const auto& currentBeefInventory = BeefManager::defaultBeefManager.getInventory();

    for (const auto& beefCut : currentBeefInventory) {
        if (id == beefCut->getId()) {
            foundBeefCut = *beefCut;
        }
    }

    return foundBeefCut;
}

Beef* BeefManager::loadNewItem(){

    int typeOfCharge = 1;
    int day, month, year;

    int id, supplier, currentStorageShelf;
    double buyingPrice;  
    double amountInStock; // in kg    
    Date buyingDate(0, 0, 0), expiringDate(0, 0, 0);
    string typeOfMeatCut;

    Date butcherDate(0, 0, 0);
    int ageOfAnimal, marblingScore, storageTemperature;
    string breedType, grade;
    char temperatureUnit = 'C'; // 'C' for Celsius
    bool isGrassFed;

    Beef* newBeefCut = nullptr;

    cout << "Por favor, ingrese '1' solo para realizar una carga normal. Si desea realizar una carga detallada ingrese '2': " << endl;
    cin >> typeOfCharge;

    if (typeOfCharge == 1)
    {
        cout << "Ingrese el tipo de corte de carne: " << endl;
        getline(cin, typeOfMeatCut);

        cout << "Ingrese el precio de compra del artículo por unidad: " << endl;
        cin >> buyingPrice;
        cin.ignore();

        cout << "Ingrese la cantidad de unidades en Stock actualmente (en kg): " << endl;
        cin >> amountInStock;
        cin.ignore();

        cout << "Por favor, ingrese el ID del proveedor: " << endl;
        cin >> supplier;
        cin.ignore();

        cout << "Por favor, ingrese el id del area de almacenamiento actual: " << endl;
        cin >> currentStorageShelf;
        cin.ignore();

        cout << "Ingrese la fecha de compra (día, mes, año): " << endl;
        cout << "Día: ";
        cin >> day;
        cout << "Mes: ";
        cin >> month;
        cout << "Año: ";
        cin >> year;
        buyingDate = Date(day, month, year);
    }
    else
    {
        cout << "Ingrese el tipo de corte de carne: " << endl;
        getline(cin, typeOfMeatCut);

        cout << "Ingrese el precio de compra del artículo por unidad: " << endl;
        cin >> buyingPrice;
        cin.ignore();

        cout << "Ingrese la cantidad de unidades en Stock actualmente (en kg): " << endl;
        cin >> amountInStock;
        cin.ignore();

        cout << "Por favor, ingrese el ID del proveedor: " << endl;
        cin >> supplier;
        cin.ignore();

        cout << "Por favor, ingrese el id del area de almacenamiento actual: " << endl;
        cin >> currentStorageShelf;
        cin.ignore();

        cout << "Ingrese la fecha de compra (día, mes, año): " << endl;
        cout << "Dia: ";
        cin >> day;
        cout << "Mes: ";
        cin >> month;
        cout << "Año: ";
        cin >> year;
        buyingDate = Date(day, month, year);

        cout << "Detalles del corte de carne: " << endl << endl;

        cout << "Ingrese la fecha de sacrificio de la pieza de carne (día, mes, año): " << endl;
        cout << "Dia: ";
        cin >> day;
        cout << "Mes: ";
        cin >> month;
        cout << "Año: ";
        cin >> year;
        expiringDate = Date(day, month, year); 

        cout << "Ingrese la edad del animal: " << endl;
        cin >> ageOfAnimal;
        cin.ignore();

        cout << "Ingrese el puntaje de marmoleo: " << endl;
        cin >> marblingScore;
        cin.ignore();

        cout << "Ingrese la temperatura de almacenamiento: (4 es lo recomendado) " << endl;
        cin >> storageTemperature;
        cin.ignore();

        cout << "Ingrese el tipo de raza: " << endl;
        getline(cin, breedType);

        cout << "Ingrese el grado de la carne: " << endl;
        getline(cin, grade);

        cout << "¿Es alimentado con pasto? (1 para si, 0 para no): " << endl;
        int grassFedInput;
        cin >> grassFedInput;
        isGrassFed = (grassFedInput == 1);
        }

    try
    {
        //hardcoded for now, since I wanted to avoid overcomplexity using time libraries
        expiringDate = Date(01, 01, 2024); 

        //create new id
        list<Beef*> currentBeefInventory = BeefManager::defaultBeefManager.getInventory();

        id = currentBeefInventory.empty() ?
        1
        :
        ((currentBeefInventory.back())->getId()) + 1;

        //check if the charge of data is detailed or not
        typeOfCharge == 1 ?

        //generate new beef cut
        newBeefCut = new Beef( id, buyingPrice, amountInStock, buyingDate, expiringDate, typeOfMeatCut, supplier, currentStorageShelf)

        :

        //generate new beef cut
        newBeefCut = new Beef(id, buyingPrice, typeOfMeatCut, storageTemperature, 'C', amountInStock, buyingDate, expiringDate, 
        supplier, currentStorageShelf, butcherDate, breedType, grade, marblingScore, isGrassFed, ageOfAnimal);

        //save it into manager class
        BeefManager::defaultBeefManager.setNewItem(newBeefCut);

        cout << endl << "Carne agregada correctamente al inventario." << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "No se ha podido agregar la carne al inventario por esta razon.";
        if(newBeefCut) delete newBeefCut;
    }

    return newBeefCut;
};

//■■■■■■■■■ default instance ■■■■■■■■■//

BeefManager BeefManager::defaultBeefManager;