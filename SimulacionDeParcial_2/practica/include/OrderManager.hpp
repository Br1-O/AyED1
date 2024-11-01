#if !defined(ORDER_MANAGER_HPP)
#define ORDER_MANAGER_HPP

    #include <iostream>
    #include <list>
    #include "./Order.hpp"

    class OrderManager
    {

        private:

            std::list<Order*> orders;

        public:

            //■■■■■■■■■ getters ■■■■■■■■■//
            
            //orders
            std::list<Order*> getOrders();

            //■■■■■■■■■ setters ■■■■■■■■■//
            
            //orders
            void setOrders(std::list<Order*> orders);

            //■■■■■■■■■ constructor ■■■■■■■■■//

            OrderManager();

            OrderManager(
            std::list<Order*> orders);

            //■■■■■■■■■ destructor ■■■■■■■■■//

            ~OrderManager();

            //■■■■■■■■■ methods ■■■■■■■■■//

            void displayActiveOrders();

            Order* getOrdersbyClientId(int id);

            Order* generateOrder(ClientManager clientManagerInstance = ClientManager::defaultClientManager, 
            ArticleManager articleManagerInstance = ArticleManager::defaultArticleManager);

            bool cancelOrder();

            //■■■■■■■■■ default instance ■■■■■■■■■//

            static OrderManager defaultOrderManager;
    };

#endif // ORDER_MANAGER_HPP