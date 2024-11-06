#if !defined(ARTICLE_HPP)
#define ARTICLE_HPP

#include <iostream>
#include <string>

class Article
{
protected:
    int id;
    std::string name;
    double price;
    int unitsInStock;
    int quantity;

public:
    //■■■■■■■■■ getters ■■■■■■■■■//

    //id
    int getId() const;

    //name
    std::string getName() const;

    //price
    double getPrice() const;

    //units in stock
    int getUnitsInStock() const;

    //quantity in order
    int getQuantity() const;

    //■■■■■■■■■ setters ■■■■■■■■■//

    //id
    void setId(int id);

    //name
    void setName(const std::string& name);

    //price
    void setPrice(double price);

    //units in stock
    void setUnitsInStock(int unitsInStock);

    //quantity in order
    void setQuantity(int quantity);

    //■■■■■■■■■ constructors ■■■■■■■■■//

    Article();

    Article(int id, const std::string& name, double price, int unitsInStock);

    //■■■■■■■■■ destructor ■■■■■■■■■//

    ~Article();
};

#endif // ARTICLE_HPP
