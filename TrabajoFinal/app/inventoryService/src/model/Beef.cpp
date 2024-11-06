#include "../../include/model/Beef.hpp"
#include "../../../utils/include/Date.hpp" // Importing Date class

#include <iostream>
#include <string>

// Default constructor
Beef::Beef() 
    : butcherDate(Date()), breedType("Desconocido"), grade("Desconocido"), 
      marblingScore(0), isGrassFed(false), ageOfAnimal(0) {}

// Constructor for not detailed charge
Beef::Beef(int id, double buyingPrice, double amountInStock, const Date& buyingDate, 
           const Date& expiringDate, const std::string& typeOfMeatCut, 
           int supplier, int currentStorageShelf)
{
    // Assign values from constructor parameters
    this->id = id;
    this->buyingPrice = buyingPrice;
    this->amountInStock = amountInStock;
    this->buyingDate = buyingDate;
    this->expiringDate = expiringDate;
    this->typeOfMeatCut = typeOfMeatCut;
    this->supplier = supplier;
    this->currentStorageShelf = currentStorageShelf;

    // Initialize the rest of the Beef class member variables
    this->butcherDate = Date();  // Default constructor for Date
    this->breedType = "";        // Default empty string
    this->grade = "";            // Default empty string
    this->marblingScore = 0;     // Default score 0
    this->isGrassFed = false;    // Default false
    this->ageOfAnimal = 0;       // Default 0
    this->storageTemperature = 4; // Default temperature (4°C)
    this->temperatureUnit = 'C'; // Default unit ('C' for Celsius)
}

// Constructor for detailed charge
Beef::Beef(int id, double buyPrice, const std::string& cut, int temp, char unit, double stock, 
           const Date& buyDate, const Date& expireDate, const int supp, const int currentStorageShelf,
           const Date& butcherDate, const std::string& breedType, const std::string& grade, 
           int marblingScore, bool isGrassFed, int ageOfAnimal)
{
    // Initializing attributes inherited from Meat
    this->id = id;
    this->buyingPrice = buyPrice;
    this->typeOfMeatCut = cut;
    this->storageTemperature = temp;
    this->temperatureUnit = unit;
    this->amountInStock = stock;
    this->buyingDate = buyDate;
    this->expiringDate = expireDate;
    this->supplier = supp;
    this->currentStorageShelf = currentStorageShelf;

    // Initializing Beef-specific attributes
    this->butcherDate = butcherDate; // Now a Date object
    this->breedType = breedType;
    this->grade = grade; // Still a string
    this->marblingScore = marblingScore;
    this->isGrassFed = isGrassFed;
    this->ageOfAnimal = ageOfAnimal;
}

// Getters
Date Beef::getButcherDate() const { return butcherDate; }
std::string Beef::getBreedType() const { return breedType; }
std::string Beef::getGrade() const { return grade; } // Still using string
int Beef::getMarblingScore() const { return marblingScore; }
bool Beef::getIsGrassFed() const { return isGrassFed; }
int Beef::getAgeOfAnimal() const { return ageOfAnimal; }

// Setters
void Beef::setButcherDate(const Date& date) { butcherDate = date; } // Now accepting Date
void Beef::setBreedType(const std::string& breed) { breedType = breed; }
void Beef::setGrade(const std::string& g) { grade = g; } // Still using string
void Beef::setMarblingScore(int score) { marblingScore = score; }
void Beef::setIsGrassFed(bool grassFed) { isGrassFed = grassFed; }
void Beef::setAgeOfAnimal(int age) { ageOfAnimal = age; }

// Override abstract methods
void Beef::displayInfo() const {
    std::cout << "Información del Corte de Carne:" << std::endl;
    std::cout << "id: " << id << std::endl;
    std::cout << "Tipo de Corte: " << typeOfMeatCut << std::endl;
    std::cout << "Precio de Compra: $" << buyingPrice << std::endl;
    std::cout << "Temperatura de Almacenamiento: " << storageTemperature << " " << temperatureUnit << std::endl;
    std::cout << "Cantidad en Stock: " << amountInStock << " kg" << std::endl;
    std::cout << "Almacenado en el area" << currentStorageShelf << std::endl;
    std::cout << "Fecha de Compra: " << buyingDate.toString() << std::endl; 
    std::cout << "Fecha de Vencimiento: " << expiringDate.toString() << std::endl; 
    std::cout << "Proveedor: " << supplier << std::endl;
    std::cout << "Fecha de Faena: " << butcherDate.toString() << std::endl; 
    std::cout << "Raza: " << breedType << std::endl;
    std::cout << "Grado: " << grade << std::endl; 
    std::cout << "Puntuación de Marmoleo: " << marblingScore << std::endl;
    std::cout << "¿Es Alimentado con Pasto?: " << (isGrassFed ? "Sí" : "No") << std::endl;
    std::cout << "Edad del Animal: " << ageOfAnimal << " meses" << std::endl;
}

int Beef::calculateShelfLife() const {
    const int maxShelfLifeWithButcherDate = 30; // Max shelf life in days with butcher date
    const int maxShelfLifeWithoutButcherDate = 7; // Max shelf life in days without butcher date
    
    if (butcherDate.isValid()) {
        return maxShelfLifeWithButcherDate;
    } else {
        return maxShelfLifeWithoutButcherDate;
    }
}
