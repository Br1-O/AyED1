#if !defined(ARTICLE_HPP)
#define ARTICLE_HPP

    #include <iostream>

    class Article
    {

        private:

            int id;
            std::string name;
            double price;
            int unitsInStock;
            int quantity;

        public:

            //■■■■■■■■■ getters ■■■■■■■■■//

            //id
            int getId();

            //name
            std::string getName();
            
            //last price
            double getPrice();

            //units in stock
            int getUnitsInStock();

            //quantity in an order
            int getQuantity();

            //■■■■■■■■■ setters ■■■■■■■■■//

            //id
            void setId(int id);

            //name
            void setName(std::string name);
            
            //price
            void setPrice(double price);

            //units in stock
            void setUnitsInStock(int unitsInStock);

            //quantity in an order
            void setQuantity(int quantity);

            //■■■■■■■■■ constructor ■■■■■■■■■//

            Article();

            Article(            
            int id,
            std::string name,
            double price,
            int unitsInStock);

            //■■■■■■■■■ destructor ■■■■■■■■■//

            ~Article();
    };

#endif // ARTICLE_HPP