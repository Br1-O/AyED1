#include "../../include/Article.hpp"

//■■■■■■■■■ getters ■■■■■■■■■//

//id
int Article::getId(){
    return id;
};

//name
std::string Article::getName(){
    return name;
};

//price
double Article::getPrice(){
    return price;
};

//units
int Article::getUnitsInStock(){
    return unitsInStock;
};

//quantity in an order
int Article::getQuantity(){
    return quantity;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//id
void Article::setId(int id){
    this->id = id;
};

//name
void Article::setName(std::string name){
    this->name = name;
};

//price
void Article::setPrice(double price){
    this->price = price;
};

//units
void Article::setUnitsInStock(int unitsInStock){
    this->unitsInStock = unitsInStock;
};

//quantity in an order
void Article::setQuantity(int quantity){
    this->quantity = quantity;
};

//■■■■■■■■■ constructor ■■■■■■■■■//

Article::Article(){};

Article::Article(            
int id,
std::string name,
double price,
int unitsInStock)
{
    this->id = id;
    this->name = name;
    this->price = price;
    this->unitsInStock = unitsInStock;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

Article::~Article(){};