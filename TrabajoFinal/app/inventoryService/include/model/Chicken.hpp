#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "Meat.hpp"
#include "../../../utils/include/Date.hpp" // Importing Date class

class Chicken : public Meat {
private:
    int weightClass;
    bool isOrganic;
    bool isFreeRange;
    bool isAntibioticFree;
    Date processedDate;

public:
    Chicken();

    // Constructor not detailed
    Chicken(int id, double buyingPrice, const std::string& typeOfMeatCut, int storageTemperature, 
            char temperatureUnit, double amountInStock, const Date& buyingDate, const Date& expiringDate, 
            int supplier, int currentStorageShelf, const Date& processedDate);

    // Constructor detailed
    Chicken(int id, double buyingPrice, const std::string& typeOfMeatCut, int storageTemperature, 
            char temperatureUnit, double amountInStock, const Date& buyingDate, const Date& expiringDate, 
            int supplier, int currentStorageShelf, int weightClass, bool isOrganic, bool isFreeRange, 
            bool isAntibioticFree, const Date& processedDate);

    // Getters
    int getWeightClass() const;
    bool getIsOrganic() const;
    bool getIsFreeRange() const;
    bool getIsAntibioticFree() const;
    Date getProcessedDate() const;

    // Setters
    void setWeightClass(int wc);
    void setIsOrganic(bool organic);
    void setIsFreeRange(bool freeRange);
    void setIsAntibioticFree(bool antibioticFree);
    void setProcessedDate(const Date& date);

    // Override abstract methods
    void displayInfo() const override;
    int calculateShelfLife() const override;
};

#endif // CHICKEN_HPP