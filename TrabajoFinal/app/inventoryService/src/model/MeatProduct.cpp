#include "../../include/model/MeatProduct.hpp"
#include <iostream>

MeatProduct::MeatProduct(std::string name, double price, int unitsInStock, Meat* typeOfMeat, float relationOfPortionWithRawMaterial){
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
