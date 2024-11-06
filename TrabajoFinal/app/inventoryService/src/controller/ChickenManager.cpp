#include <iostream>
#include <string>
#include <list>
#include "../../include/model/Chicken.hpp"
#include "../../include/controller/ChickenManager.hpp"
#include "../../../utils/include/Utils.hpp"

using namespace std;

//■■■■■■■■■ getters ■■■■■■■■■//

// chicken inventory
list<Chicken*> ChickenManager::getInventory() const {
    return this->inventory;
};

//■■■■■■■■■ setters ■■■■■■■■■//

// chicken inventory
void ChickenManager::setNewItem(Chicken* chickenCut) {
    (this->inventory).push_back(chickenCut);
};

//■■■■■■■■■ constructor ■■■■■■■■■//

ChickenManager::ChickenManager() {};

ChickenManager::ChickenManager(list<Chicken*> inventory) {
    this->inventory = inventory;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

ChickenManager::~ChickenManager() {
    // Manager classes are singletons and persist through app lifetime, so no default destructor needed
};

//■■■■■■■■■ methods ■■■■■■■■■//

void ChickenManager::displayInventoryList() const {
    list<Chicken*> currentChickenInventory = ChickenManager::defaultChickenManager.getInventory();

    string title = "Listado de inventario de pollo: ";
    string lineSeparator = "---------------------------------";

    cout << title << endl;

    for (const auto &chickenCut : currentChickenInventory) {
        cout << lineSeparator << endl;
        chickenCut->displayInfo();
        cout << lineSeparator << endl;
    }

    cout << endl;
};

Chicken ChickenManager::getItemById(int id) {
    Chicken foundChickenCut;
    foundChickenCut.setId(0);

    const auto& currentChickenInventory = ChickenManager::defaultChickenManager.getInventory();

    for (const auto& chickenCut : currentChickenInventory) {
        if (id == chickenCut->getId()) {
            foundChickenCut = *chickenCut;
        }
    }

    return foundChickenCut;
}

Chicken* ChickenManager::loadNewItem() {
    int typeOfCharge = 1;
    int day, month, year;

    int id, supplier, currentStorageShelf;
    double buyingPrice;  
    double amountInStock; // in kg    
    Date buyingDate(0, 0, 0), expiringDate(0, 0, 0);
    string typeOfMeatCut;

    int storageTemperature;
    char temperatureUnit = 'C'; // 'C' for Celsius
    int weightClass;
    bool isOrganic;
    bool isFreeRange;
    bool isAntibioticFree;
    Date processedDate;

    Chicken* newChickenCut = nullptr;

    cout << "Por favor, ingrese '1' solo para realizar una carga normal. Si desea realizar una carga detallada ingrese '2': " << endl;
    cin >> typeOfCharge;

    if (typeOfCharge == 1) {
         cout << "Ingrese la parte del pollo: " << endl;
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
    } else {
        cout << "Ingrese el tipo de corte de pollo: " << endl;
        getline(cin, typeOfChickenCut);

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

        cout << "Detalles del corte de pollo: " << endl << endl;

        cout << "Ingrese la edad del animal: " << endl;
        cin >> ageOfAnimal;
        cin.ignore();

        cout << "Ingrese el tipo de raza: " << endl;
        getline(cin, breedType);

        cout << "¿Es orgánico? (1 para si, 0 para no): " << endl;
        int organicInput;
        cin >> organicInput;
        isOrganic = (organicInput == 1);
    }

    try {
        // hardcoded for now
        expiringDate = Date(01, 01, 2024);

        // create new id
        list<Chicken*> currentChickenInventory = ChickenManager::defaultChickenManager.getInventory();

        id = currentChickenInventory.empty() ?
              1
            : ((currentChickenInventory.back())->getId()) + 1;

        newChickenCut = new Chicken(buyingPrice, amountInStock, buyingDate, expiringDate, typeOfChickenCut, supplier, currentStorageShelf, ageOfAnimal, breedType, isOrganic);

        ChickenManager::defaultChickenManager.setNewItem(newChickenCut);

        cout << endl << "Pollo agregado correctamente al inventario." << endl;
    } catch (const std::exception& e) {
        cerr << e.what() << '\n';
        cout << "No se ha podido agregar el pollo al inventario por esta razón.";
        if (newChickenCut) delete newChickenCut;
    }

    return newChickenCut;
};

//■■■■■■■■■ default instance ■■■■■■■■■//

ChickenManager ChickenManager::defaultChickenManager;