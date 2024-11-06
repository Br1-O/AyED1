#ifndef MEAT_HPP
#define MEAT_HPP

#include <string>
#include <iostream>
#include "../../../utils/include/Date.hpp"

class Meat {
    protected:
        int id;
        double buyingPrice;
        std::string typeOfMeatCut;
        int storageTemperature; // in degrees Celsius
        char temperatureUnit; // 'C' for Celsius
        double amountInStock; // in kg
        Date buyingDate;
        Date expiringDate;
        int supplier; // Supplier as int
        int currentStorageShelf; // Corrected member for storage shelf

    public:
        // Default constructor
        Meat() 
            : id(0), buyingPrice(0.0), storageTemperature(4), temperatureUnit('C'), amountInStock(0.0), 
              supplier(0), currentStorageShelf(0) {} // Default value for storage shelf

        // Parameterized constructor
        Meat(int id, double buyPrice, const std::string& cut, int temp, char unit, double stock, 
             const Date& buyDate, const Date& expireDate, int supp, int shelf) // Added shelf parameter
            : id(id), buyingPrice(buyPrice), typeOfMeatCut(cut), storageTemperature(temp), 
              temperatureUnit(unit), amountInStock(stock), buyingDate(buyDate), expiringDate(expireDate), 
              supplier(supp), currentStorageShelf(shelf) {} // Initialize storage shelf

        // Destructor
        virtual ~Meat() {}

        // Getters
        int getId() const { return id; }
        double getBuyingPrice() const { return buyingPrice; }
        std::string getTypeOfMeatCut() const { return typeOfMeatCut; }
        int getStorageTemperature() const { return storageTemperature; }
        char getTemperatureUnit() const { return temperatureUnit; }
        double getAmountInStock() const { return amountInStock; }
        Date getBuyingDate() const { return buyingDate; }
        Date getExpiringDate() const { return expiringDate; }
        int getSupplier() const { return supplier; }
        int getCurrentStorageShelf() const { return currentStorageShelf; } // Getter for storage shelf

        // Setters
        void setId(int newId) { id = newId; }
        void setBuyingPrice(double buyPrice) { buyingPrice = buyPrice; }
        void setTypeOfMeatCut(const std::string& cut) { typeOfMeatCut = cut; }
        void setStorageTemperature(int temp) { storageTemperature = temp; }
        void setTemperatureUnit(char unit) { temperatureUnit = unit; }
        void setAmountInStock(double stock) { amountInStock = stock; }
        void setBuyingDate(const Date& date) { buyingDate = date; }
        void setExpiringDate(const Date& date) { expiringDate = date; }
        void setSupplier(int supp) { supplier = supp; }
        void setCurrentStorageShelf(int shelf) { currentStorageShelf = shelf; } // Setter for storage shelf

        // Pure virtual function for calculating shelf life
        virtual int calculateShelfLife() const = 0; //inDays

        // Pure virtual function for displaying info
        virtual void displayInfo() const = 0; 
};

#endif // MEAT_HPP