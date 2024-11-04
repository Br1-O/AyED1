#if !defined(ORDER_HPP)
#define ORDER_HPP

#include <iostream>
#include <list>
#include "./Client.hpp"
#include "./Employee.hpp"
#include "./Article.hpp"

class Order
{

private:
    int id;
    Client client;
    Employee employee;
    std::list<Article> articles;
    double totalCost;

public:
    //■■■■■■■■■ getters ■■■■■■■■■//

    // id
    int getId() const;

    // client
    Client getClient() const;

    // employee
    Employee getEmployee() const;

    // articles
    std::list<Article> getArticles() const;

    // total cost
    double getTotalCost() const;

    //■■■■■■■■■ setters ■■■■■■■■■//

    // id
    void setId(int id);

    // client
    void setClient(const Client& client);

    // employee
    void setEmployee(const Employee& employee);

    // articles
    void setArticles(const std::list<Article>& articles);

    // total cost
    void setTotalCost(double totalCost);

    //■■■■■■■■■ constructor ■■■■■■■■■//

    Order();

    Order(            
        int id,
        const Client& client,
        const Employee& employee,
        const std::list<Article>& articles,
        double totalCost);

    //■■■■■■■■■ destructor ■■■■■■■■■//

    ~Order();
};

#endif // ORDER_HPP