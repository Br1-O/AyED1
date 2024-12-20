#include "../../include/Order.hpp"
#include "../../include/Client.hpp"
#include "../../include/Article.hpp"
#include <list> // Include for std::list

//■■■■■■■■■ getters ■■■■■■■■■//

// id
int Order::getId() const {
    return id;
}

// client
Client Order::getClient() const {
    return client;
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
void Order::setClient(const Client& client) { // Pass by const reference
    this->client = client;
}

// articles
void Order::setArticles(const std::list<Article>& articles) { // Pass by const reference
    this->articles = articles;
}

// total cost
void Order::setTotalCost(double totalCost) {
    this->totalCost = totalCost;
}

//■■■■■■■■■ constructor ■■■■■■■■■//

Order::Order(int id, const Client& client, const std::list<Article>& articles, double totalCost)
    : id(id), client(client), articles(articles), totalCost(totalCost) { // Use initializer list
}

//■■■■■■■■■ destructor ■■■■■■■■■//

Order::~Order() {
    // Destructor implementation (if needed)
}