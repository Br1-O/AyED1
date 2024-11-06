#include "../../include/model/Chicken.hpp"
#include "../../../utils/include/Date.hpp" // Importing Date class

#include <iostream>

// Default constructor
Chicken::Chicken(){};

// Constructor using all Meat properties
Chicken::Chicken(int id, double buyingPrice, const std::string& typeOfMeatCut, int storageTemperature, 
                 char temperatureUnit, double amountInStock, const Date& buyingDate, 
                 const Date& expiringDate, int supplier, int currentStorageShelf, char chickenClass)
:Meat(id, buyingPrice, typeOfMeatCut, storageTemperature, temperatureUnit, amountInStock, 
            buyingDate, expiringDate, supplier, currentStorageShelf)
{
    this->chickenClass = chickenClass; 
}

// Getters
char Chicken::getChickenClass() const {
    return chickenClass;
}


// Setters
void Chicken::setChickenClass(char c) {
    chickenClass = c;
}

// Override the displayInfo() method from the Meat class
void Chicken::displayInfo() const {

    Meat::displayInfo();
    
    std::cout << "Clase: " << chickenClass << std::endl;
}


// Override the calculateShelfLife() method from the Meat class
int Chicken::calculateShelfLife() const {
    
    if (chickenClass == 1) {
        return 7; // 7 days shelf life
    }
    return 5; // 5 days shelf life
}