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
            std::list<Article*> articles;
            double totalCost;

        public:

            //■■■■■■■■■ getters ■■■■■■■■■//

            //id
            int getId();

            //client
            Client getClient();
            
            //articles
            std::list<Article*> getArticles();

            //total cost
            double getTotalCost();

            //■■■■■■■■■ setters ■■■■■■■■■//

            //id
            void setId(int id);

            //client
            void setClient(Client client);
            
            //articles
            void setArticle(std::list<Article*> articles);

            //total cost
            void setTotalCost(double totalCost);


            //■■■■■■■■■ constructor ■■■■■■■■■//

            Order(            
            int id,
            Client client,
            std::list<Article*> articles,
            double totalCost);

            //■■■■■■■■■ destructor ■■■■■■■■■//

            ~Order();
    };

#endif // ORDER_HPP