#ifndef PORK_HPP
#define PORK_HPP

#include "Meat.hpp"

class Pork : public Meat {
private:
    int breedType;

public:
    // Constructor using Meat properties plus breedType
    Pork(int id, double buyingPrice, const std::string& typeOfMeatCut, int storageTemperature, 
         char temperatureUnit, double amountInStock, const Date& buyingDate, 
         const Date& expiringDate, int supplier, int currentStorageShelf, int breedType);

    // Getter
    int getBreedType() const;

    // Setter
    void setBreedType(const int& breed);

    // Override abstract methods
    void displayInfo() const override;
    int calculateShelfLife() const override;
};

#endif // PORK_HPP