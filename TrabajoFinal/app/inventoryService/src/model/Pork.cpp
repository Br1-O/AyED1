#include "../../include/model/Pork.hpp"
#include <iostream>

Pork::Pork(std::string cut, int temp, char unit, double stock, std::string butcherDate, 
           std::string breedType, bool isHeritageBreed, SmokingLevel smokingLevel, bool isCured)
    : Meat(cut, temp, unit, stock), butcherDate(butcherDate), breedType(breedType), 
      isHeritageBreed(isHeritageBreed), smokingLevel(smokingLevel), isCured(isCured) {}

// Getters
std::string Pork::getButcherDate() const { return butcherDate; }
std::string Pork::getBreedType() const { return breedType; }
bool Pork::getIsHeritageBreed() const { return isHeritageBreed; }
SmokingLevel Pork::getSmokingLevel() const { return smokingLevel; }
bool Pork::getIsCured() const { return isCured; }

// Setters
void Pork::setButcherDate(const std::string& date) { butcherDate = date; }
void Pork::setBreedType(const std::string& breed) { breedType = breed; }
void Pork::setIsHeritageBreed(bool heritage) { isHeritageBreed = heritage; }
void Pork::setSmokingLevel(SmokingLevel level) { smokingLevel = level; }
void Pork::setIsCured(bool cured) { isCured = cured; }

void Pork::displayInfo() const {
    std::cout << "Pork Cut: " << typeOfMeatCut << ", Breed: " << breedType 
              << ", Heritage Breed: " << isHeritageBreed << ", Smoking Level: " 
              << static_cast<int>(smokingLevel) << ", Cured: " << isCured 
              << ", Butcher Date: " << butcherDate << std::endl;
}

int Pork::calculateShelfLife() const {
    return (storageTemperature < 4) ? (isCured ? 14 : 5) : 3;
}