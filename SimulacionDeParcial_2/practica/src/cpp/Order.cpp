#include "../../include/Order.hpp"
#include "../../include/Client.hpp"
#include "../../include/Article.hpp"

//■■■■■■■■■ getters ■■■■■■■■■//

//id
int Order::getId(){
    return id;
};

//client
Client Order::getClient(){
    return client;
};

//articles
std::list<Article*> Order::getArticles(){
    return articles;
};

//total cost
double Order::getTotalCost(){
    return totalCost;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//id
void Order::setId(int id){
    this->id = id;
};

//client
void Order::setClient(Client client){
    this->client = client;
};

//articles
void Order::setArticle(std::list<Article*> articles){
    this->articles = articles;
};

//total cost
void Order::setTotalCost(double totalCost){
    this->totalCost = totalCost;
};

//■■■■■■■■■ constructor ■■■■■■■■■//

Order::Order(            
int id,
Client client,
std::list<Article*> articles,
double totalCost)
{
this->id=id;
this->client=client;
this->articles=articles;
this->totalCost=totalCost;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

Order::~Order(){
    for (Article* article : articles) {
        delete article;
    }
};