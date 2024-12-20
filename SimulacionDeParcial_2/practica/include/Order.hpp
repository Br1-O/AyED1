#if !defined(ORDER_HPP)
#define ORDER_HPP

#include <iostream>
#include <list>
#include "./Client.hpp"
#include "./Article.hpp"

class Order
{

private:
    int id;
    Client client;
    std::list<Article> articles;
    double totalCost;

public:
    //■■■■■■■■■ getters ■■■■■■■■■//

    // id
    int getId() const;

    // client
    Client getClient() const;

    // articles
    std::list<Article> getArticles() const;

    // total cost
    double getTotalCost() const;

    //■■■■■■■■■ setters ■■■■■■■■■//

    // id
    void setId(int id);

    // client
    void setClient(const Client& client); // Pass by const reference

    // articles
    void setArticles(const std::list<Article>& articles); // Pass by const reference

    // total cost
    void setTotalCost(double totalCost);

    //■■■■■■■■■ constructor ■■■■■■■■■//

    Order(            
        int id,
        const Client& client,           // Pass by const reference
        const std::list<Article>& articles, // Pass by const reference
        double totalCost);

    //■■■■■■■■■ destructor ■■■■■■■■■//

    ~Order();
};

#endif // ORDER_HPP