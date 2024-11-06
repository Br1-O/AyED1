#include <iostream>
#include <string>
#include <list>
#include "../../include/model/Meat.hpp"
#include "../../include/model/Beef.hpp"
#include "../../include/model/Chicken.hpp"
#include "../../include/model/Pork.hpp"
#include "../../include/controller/MeatManager.hpp"
#include "../../../utils/include/Utils.hpp"
#include "../../../utils/include/Date.hpp" // Importing Date class

using namespace std;

//■■■■■■■■■ getters ■■■■■■■■■//

// Meat articles
list<Meat*> MeatManager::getInventory() const {
    return this->inventory;
};

//■■■■■■■■■ setters ■■■■■■■■■//

// Meat articles
void MeatManager::setNewItem(Meat* meatCut) {
    (this->inventory).push_back(meatCut);
};

//■■■■■■■■■ constructor ■■■■■■■■■//

MeatManager::MeatManager() {}

MeatManager::MeatManager(list<Meat*> inventory) {
    this->inventory = inventory;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

MeatManager::~MeatManager() {
    // Since Managers classes are singletons they should not be destroyed during any time of the life time of this program
};

//■■■■■■■■■ methods ■■■■■■■■■//

void MeatManager::displayInventoryList() const {
    list<Meat*> currentMeatInventory = MeatManager::defaultMeatManager.getInventory();

    string title = "Listado de inventario de carne: ";
    string lineSeparator = "---------------------------------";

    cout << title << endl;

    for (const auto& meatCut : currentMeatInventory) {
        cout << lineSeparator << endl;

        //display info using polimorph
        meatCut->displayInfo();
        
        cout << lineSeparator << endl;
    }

    cout << endl;
};

Meat* MeatManager::getItemById(int id) {
    Meat* foundMeatCut = nullptr;

    const auto& currentMeatInventory = MeatManager::defaultMeatManager.getInventory();

    for (const auto& meatCut : currentMeatInventory) {
        if (id == meatCut->getId()) {
            foundMeatCut = meatCut;
        }
    }

    return foundMeatCut;
}

Meat* MeatManager::loadNewItem() {
    int day, month, year;
    int childType; 

    int id, supplier, currentStorageShelf;
    double buyingPrice;
    double amountInStock; // in kg    
    Date buyingDate(0, 0, 0), expiringDate(0, 0, 0);
    string typeOfMeatCut;

    Meat* newMeatCut = nullptr;
    
    cout << "Ingrese el tipo de carne que desea agregar al inventario: " << endl;
    cout << "1. Carne vacuna " << endl;
    cout << "2. Pollo " << endl;
    cout << "3. Carne de cerdo " << endl;
    cin >> childType;
    cin.ignore();

    cout << "Ingrese el tipo de corte de carne: " << endl << "Por ej: Vacio, Nalga, Peceto, Pata, Muslo, etc." << endl;
    getline(cin, typeOfMeatCut);

    cout << "Ingrese el precio de compra del articulo por unidad: " << endl;
    cin >> buyingPrice;
    cin.ignore();

    cout << "Ingrese la cantidad en kg: " << endl;
    cin >> amountInStock;
    cin.ignore();

    cout << "Por favor, ingrese el ID del proveedor: " << endl;
    cin >> supplier;
    cin.ignore();

    cout << "Por favor, ingrese el id del area de almacenamiento actual: " << endl;
    cin >> currentStorageShelf;
    cin.ignore();

    cout << "Ingrese la fecha de compra (dia, mes, año): " << endl;
    cout << "Dia: ";
    cin >> day;
    cin.ignore();
    cout << "Mes: ";
    cin >> month;
    cin.ignore();
    cout << "Año: ";
    cin >> year;
    cin.ignore();
    buyingDate = Date(day, month, year);

    try {

        //hardcoded for now, since I wanted to avoid overcomplexity using time libraries
        expiringDate = Date(01, 01, 2024);

        //create new id
        list<Meat*> currentMeatInventory = MeatManager::defaultMeatManager.getInventory();

        id = currentMeatInventory.empty() ?
        1 :
        ((currentMeatInventory.back())->getId()) + 1;

        //casting based on the current meat type
        if (childType == 1) {

            int grade; 
            
            cout << "Por favor, ingrese el grado de la carne de res: (1 - 5)" << endl;
            cout << "1 - Excelente" << endl;
            cout << "2 - Muy buena" << endl;
            cout << "3 - Buena" << endl;
            cout << "4 - Aceptable" << endl;
            cout << "5 - Baja calidad" << endl;
            cin >> grade;
            cin.ignore();

            //create beef instance
            Beef* newBeefCut = new Beef( id,  buyingPrice, typeOfMeatCut, 4, 'C', amountInStock, 
            buyingDate, expiringDate, supplier, currentStorageShelf, grade);

            //assign Meat pointer the direction of the beef pointer 
            newMeatCut = newBeefCut;
        } 
        else if (childType == 2) {

            char chickenClass; 
            
            cout << "Por favor, ingrese la clase de la carne de pollo: (A - C)" << endl;
            cout << "A - Alta calidad" << endl;
            cout << "B - Calidad media" << endl;
            cout << "C - Baja calidad" << endl;
            cin >> chickenClass;
            cin.ignore();
            
            //create chicken instance
            Chicken* chickenCut = new Chicken( id,  buyingPrice, typeOfMeatCut, 4, 'C', amountInStock, 
            buyingDate, expiringDate, supplier, currentStorageShelf, chickenClass);

            //assign Meat pointer the direction of the Chicken pointer 
            newMeatCut = chickenCut;
        } 
        else {

            int breedType; 
            
            cout << "Por favor, ingrese el tipo de raza del cerdo: (1 - 5)" << endl;
            cout << "1 - Raza premium" << endl;
            cout << "2 - Raza de calidad superior" << endl;
            cout << "3 - Raza estandar" << endl;
            cout << "4 - Raza de calidad media" << endl;
            cout << "5 - Raza economica" << endl;        
            cin >> breedType;
            cin.ignore();
            
            //create pork instance
            Pork* porkCut = new Pork( id,  buyingPrice, typeOfMeatCut, 4, 'C', amountInStock, 
            buyingDate, expiringDate, supplier, currentStorageShelf, breedType);

            //assign Meat pointer the direction of the Pork pointer 
            newMeatCut = porkCut;
        }

        //save via polimorph into manager class
        MeatManager::defaultMeatManager.setNewItem(newMeatCut);

        cout << endl << "Carne agregada correctamente al inventario." << endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        cout << "No se ha podido agregar la carne al inventario por esta razon.";
        if (newMeatCut) delete newMeatCut;
    }

    return newMeatCut;
};

//■■■■■■■■■ default instance ■■■■■■■■■//

MeatManager MeatManager::defaultMeatManager;