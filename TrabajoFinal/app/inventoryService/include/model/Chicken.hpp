#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "Meat.hpp"
#include "../../../utils/include/Date.hpp" // Importing Date class

class Chicken : public Meat {
private:
    char chickenClass; // A, B, C

public:
    Chicken();

    // Constructor using all Meat properties
    Chicken(int id, double buyingPrice, const std::string& typeOfMeatCut, int storageTemperature, 
            char temperatureUnit, double amountInStock, const Date& buyingDate, 
            const Date& expiringDate, int supplier, int currentStorageShelf, char chickenClass);

    // Getter for clase
    char getChickenClass() const;

    // Setter for clase
    void setChickenClass(char c);

    // Override abstract methods
    void displayInfo() const override;
    int calculateShelfLife() const override;
};

#endif // CHICKEN_HPP