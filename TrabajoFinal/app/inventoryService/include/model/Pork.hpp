#ifndef PORK_HPP
#define PORK_HPP

#include "Meat.hpp"

enum class SmokingLevel { NONE, LIGHT, HEAVY }; // Example smoking level enumeration

class Pork : public Meat {
private:
    std::string butcherDate;
    std::string breedType;
    bool isHeritageBreed;
    SmokingLevel smokingLevel;
    bool isCured;

public:
    Pork(std::string cut, int temp, char unit, double stock, std::string butcherDate, 
         std::string breedType, bool isHeritageBreed, SmokingLevel smokingLevel, bool isCured);

    // Getters
    std::string getButcherDate() const;
    std::string getBreedType() const;
    bool getIsHeritageBreed() const;
    SmokingLevel getSmokingLevel() const;
    bool getIsCured() const;

    // Setters
    void setButcherDate(const std::string& date);
    void setBreedType(const std::string& breed);
    void setIsHeritageBreed(bool heritage);
    void setSmokingLevel(SmokingLevel level);
    void setIsCured(bool cured);

    // Override abstract methods
    void displayInfo() const override;
    int calculateShelfLife() const override;
};

#endif // PORK_HPP