#include "../../include/model/Pork.hpp"
#include <iostream>

// Constructor using Meat properties plus breedType
Pork::Pork(int id, double buyingPrice, const std::string& typeOfMeatCut, int storageTemperature, 
           char temperatureUnit, double amountInStock, const Date& buyingDate, 
           const Date& expiringDate, int supplier, int currentStorageShelf, int breedType)
    : Meat(id, buyingPrice, typeOfMeatCut, storageTemperature, temperatureUnit, amountInStock, 
           buyingDate, expiringDate, supplier, currentStorageShelf), breedType(breedType)
{
}

// Getter for breedType
int Pork::getBreedType() const {
    return breedType;
}

// Setter for breedType
void Pork::setBreedType(const int& breed) {
    breedType = breed;
}

// Example of overriding displayInfo method
void Pork::displayInfo() const {

    Meat::displayInfo(); 

    std::cout << "Tipo de Raza: " << breedType << std::endl; 
}

int Pork::calculateShelfLife() const {
    if (breedType == 1) {
        return 7; // 7 days shelf life
    }
    return 5; // 5 days shelf life   
}
