#include "../../../businessService/include/model/Article.hpp"
#include "../../include/model/MeatProduct.hpp"
#include "../../include/controller/MeatManager.hpp"

#include <iostream>

MeatProduct::MeatProduct(){};

MeatProduct::MeatProduct(int id, std::string name, double price, int unitsInStock, Meat* typeOfMeat, float relationOfPortionWithRawMaterial){
    this->id = id;
    this->name = name;
    this->price = price;
    this->unitsInStock = unitsInStock;
    this->typeOfMeat = typeOfMeat;
    this->relationOfPortionWithRawMaterial = relationOfPortionWithRawMaterial;
};

// Getters
Meat* MeatProduct::getTypeOfMeat() const { return typeOfMeat; }
float MeatProduct::getRelationOfPortionWithRawMaterial() const { return relationOfPortionWithRawMaterial; }

// Setters
void MeatProduct::setTypeOfMeat(Meat* meat) { typeOfMeat = meat; }
void MeatProduct::setRelationOfPortionWithRawMaterial(float relation) { relationOfPortionWithRawMaterial = relation; }

//methods

void MeatProduct::displayInfo() const{

    //calls for display info of mother Article class
    Article::displayInfo();

    std::cout << std::endl << std::endl << "Hecho con la carne: " << std::endl;

    //calls for display info of contained Meat object
    (this->typeOfMeat)->displayInfo();

    std::cout << "La proporcion entre materia prima y este producto es de: " << relationOfPortionWithRawMaterial << std::endl << std::endl;
};