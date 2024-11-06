#include "../../include/model/Chicken.hpp"
#include "../../../utils/include/Date.hpp" // Importing Date class

#include <iostream>

// Default constructor
Chicken::Chicken() 
    : weightClass(0), isOrganic(false), isFreeRange(false), isAntibioticFree(false), processedDate(Date(0,0,0)) {
    // Default values for base class members if needed
    id = 0;
    buyingPrice = 0.0;
    typeOfMeatCut = "";
    storageTemperature = 0;
    temperatureUnit = 'C';
    amountInStock = 0.0;
    supplier = 0;
    currentStorageShelf = 0;
}

// Constructor using all Meat properties
Chicken::Chicken(int id, double buyingPrice, const std::string& typeOfMeatCut, int storageTemperature, 
                 char temperatureUnit, double amountInStock, const Date& buyingDate, const Date& expiringDate, 
                 int supplier, int currentStorageShelf, const Date& processedDate)
    : Meat(id, buyingPrice, typeOfMeatCut, storageTemperature, temperatureUnit, amountInStock, 
           buyingDate, expiringDate, supplier, currentStorageShelf) 
{
    // No need to initialize Chicken-specific properties, they can be set to default values
    weightClass = 0; 
    isOrganic = false;
    isFreeRange = false;
    isAntibioticFree = false;
}

// Constructor using all Chicken and Meat properties
Chicken::Chicken(int id, double buyingPrice, const std::string& typeOfMeatCut, int storageTemperature, 
                 char temperatureUnit, double amountInStock, const Date& buyingDate, const Date& expiringDate, 
                 int supplier, int currentStorageShelf, int weightClass, bool isOrganic, bool isFreeRange, 
                 bool isAntibioticFree, const Date& processedDate)
    : Meat(id, buyingPrice, typeOfMeatCut, storageTemperature, temperatureUnit, amountInStock, 
           buyingDate, expiringDate, supplier, currentStorageShelf) 
{
    // Initialize Chicken-specific properties
    this->weightClass = weightClass;
    this->isOrganic = isOrganic;
    this->isFreeRange = isFreeRange;
    this->isAntibioticFree = isAntibioticFree;
    this->processedDate = processedDate;
}

// Getters
int Chicken::getWeightClass() const {
    return weightClass;
}

bool Chicken::getIsOrganic() const {
    return isOrganic;
}

bool Chicken::getIsFreeRange() const {
    return isFreeRange;
}

bool Chicken::getIsAntibioticFree() const {
    return isAntibioticFree;
}

Date Chicken::getProcessedDate() const {
    return processedDate;
}

// Setters
void Chicken::setWeightClass(int wc) {
    weightClass = wc;
}

void Chicken::setIsOrganic(bool organic) {
    isOrganic = organic;
}

void Chicken::setIsFreeRange(bool freeRange) {
    isFreeRange = freeRange;
}

void Chicken::setIsAntibioticFree(bool antibioticFree) {
    isAntibioticFree = antibioticFree;
}

void Chicken::setProcessedDate(const Date& date) {
    processedDate = date;
}

// Override the displayInfo() method from the Meat class
void Chicken::displayInfo() const {
    std::cout << "Información del Pollo:" << std::endl;
    std::cout << "Corte: " << typeOfMeatCut << std::endl;
    std::cout << "Clase de Peso: " << weightClass << std::endl;
    std::cout << "Organico: " << (isOrganic ? "Sí" : "No") << std::endl;
    std::cout << "De Libre Pastoreo: " << (isFreeRange ? "Sí" : "No") << std::endl;
    std::cout << "Libre de Antibioticos: " << (isAntibioticFree ? "Sí" : "No") << std::endl;
    std::cout << "Fecha de Procesamiento: " << processedDate.toString() << std::endl;
    std::cout << "Temperatura de Almacenamiento: " << storageTemperature << " " << temperatureUnit << std::endl;
    std::cout << "Cantidad en Stock: " << amountInStock << " unidades" << std::endl;
}


// Override the calculateShelfLife() method from the Meat class
int Chicken::calculateShelfLife() const {
    // Example: If the chicken is organic and antibiotic-free, the shelf life is 7 days, else it's 5 days.
    if (isOrganic && isAntibioticFree) {
        return 7; // 7 days shelf life
    }
    return 5; // 5 days shelf life
}