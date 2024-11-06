#ifndef BEEF_HPP
#define BEEF_HPP

#include "Meat.hpp"
#include <string>
#include "../../../utils/include/Date.hpp" // Importing Date class

class Beef : public Meat {
private:
    Date butcherDate;
    std::string breedType;
    std::string grade;
    int marblingScore;
    bool isGrassFed;
    int ageOfAnimal;

public:
    // Default constructor
    Beef();

    // Constructor for not detailed charge
    Beef(int id, double buyingPrice, double amountInStock, const Date& buyingDate, 
         const Date& expiringDate, const std::string& typeOfMeatCut, 
         int supplier, int currentStorageShelf);

    // Constructor for full detail charge
    Beef(int id, double buyPrice, const std::string& cut, int temp, char unit, double stock, 
         const Date& buyDate, const Date& expireDate, const int supp, const int currentStorageShelf,
         const Date& butcherDate, const std::string& breedType, const std::string& grade, 
         int marblingScore, bool isGrassFed, int ageOfAnimal);

    // Getters for Beef-specific attributes
    Date getButcherDate() const;
    std::string getBreedType() const;
    std::string getGrade() const; // Still using string
    int getMarblingScore() const;
    bool getIsGrassFed() const;
    int getAgeOfAnimal() const;

    // Setters for Beef-specific attributes
    void setButcherDate(const Date& date); // Now accepting Date
    void setBreedType(const std::string& breed);
    void setGrade(const std::string& g); // Still using string
    void setMarblingScore(int score);
    void setIsGrassFed(bool grassFed);
    void setAgeOfAnimal(int age);

    // Override abstract methods
    void displayInfo() const override;
    int calculateShelfLife() const override; //inDays
};

#endif // BEEF_HPP