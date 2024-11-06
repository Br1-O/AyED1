#include "../../include/model/Article.hpp"

//■■■■■■■■■ getters ■■■■■■■■■//

//id
int Article::getId() const {
    return id;
}

//name
std::string Article::getName() const {
    return name;
}

//price
double Article::getPrice() const {
    return price;
}

//units
int Article::getUnitsInStock() const {
    return unitsInStock;
}

//quantity in an order
int Article::getQuantity() const {
    return quantity;
}

//■■■■■■■■■ setters ■■■■■■■■■//

//id
void Article::setId(int id) {
    this->id = id;
}

//name
void Article::setName(const std::string& name) {
    this->name = name;
}

//price
void Article::setPrice(double price) {
    this->price = price;
}

//units
void Article::setUnitsInStock(int unitsInStock) {
    this->unitsInStock = unitsInStock;
}

//quantity in an order
void Article::setQuantity(int quantity) {
    this->quantity = quantity;
}

//■■■■■■■■■ constructor ■■■■■■■■■//

Article::Article() : id(0), price(0.0), unitsInStock(0), quantity(0) {}

Article::Article(int id, const std::string& name, double price, int unitsInStock)
    : id(id), name(name), price(price), unitsInStock(unitsInStock), quantity(0) {}

//■■■■■■■■■ destructor ■■■■■■■■■//

Article::~Article() {}

//■■■■■■■■■ methods ■■■■■■■■■//

void Article::displayInfo() const{
    std::cout << "Id: " << this->getId() << std::endl;
    std::cout << "Nombre: " << this->getName() << std::endl;
    std::cout << "Producto: " << this->getPrice() << std::endl;
    std::cout << "Cantidad en stock: " << this->getUnitsInStock() << std::endl;
};

