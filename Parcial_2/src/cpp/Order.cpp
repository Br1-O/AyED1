#include "../../include/Order.hpp"
#include "../../include/Client.hpp"
#include "../../include/Employee.hpp"
#include "../../include/Article.hpp"
#include <list>

//■■■■■■■■■ getters ■■■■■■■■■//

// id
int Order::getId() const {
    return id;
}

// client
Client Order::getClient() const {
    return client;
}

// employee
Employee Order::getEmployee() const {
    return employee;
}

// articles
std::list<Article> Order::getArticles() const {
    return articles;
}

// total cost
double Order::getTotalCost() const {
    return totalCost;
}

//■■■■■■■■■ setters ■■■■■■■■■//

// id
void Order::setId(int id) {
    this->id = id;
}

// client
void Order::setClient(const Client& client) {
    this->client = client;
}

// employee
void Order::setEmployee(const Employee& employee) {
    this->employee = employee;
}

// articles
void Order::setArticles(const std::list<Article>& articles) {
    this->articles = articles;
}

// total cost
void Order::setTotalCost(double totalCost) {
    this->totalCost = totalCost;
}

//■■■■■■■■■ constructor ■■■■■■■■■//

Order::Order(int id, const Client& client, const Employee& employee, const std::list<Article>& articles, double totalCost)
    : id(id), client(client), employee(employee), articles(articles), totalCost(totalCost) {
}

//■■■■■■■■■ destructor ■■■■■■■■■//

Order::~Order() {
    // Destructor implementation (if needed)
}