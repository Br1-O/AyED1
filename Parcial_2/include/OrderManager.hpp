#if !defined(ORDER_MANAGER_HPP)
#define ORDER_MANAGER_HPP

    #include <iostream>
    #include <list>
    #include "./Order.hpp"
    #include "./ArticleManager.hpp"
    #include "./ClientManager.hpp"
    #include "./EmployeeManager.hpp"

    class OrderManager
    {

        private:

            std::list<Order*> orders;

        public:

            //■■■■■■■■■ getters ■■■■■■■■■//
            
            //orders
            std::list<Order*> getOrders() const;

            //■■■■■■■■■ setters ■■■■■■■■■//
            
            //orders
            void setNewOrders(Order* order);

            //■■■■■■■■■ constructor ■■■■■■■■■//

            OrderManager();

            OrderManager(
            std::list<Order*> orders);

            //■■■■■■■■■ destructor ■■■■■■■■■//

            ~OrderManager();

            //■■■■■■■■■ methods ■■■■■■■■■//

            void displayActiveOrders();

            std::list<Order*> getOrdersbyClientId(int id);

            Order* generateOrder(ClientManager clientManagerInstance = ClientManager::defaultClientManager, 
            ArticleManager articleManagerInstance = ArticleManager::defaultArticleManager, 
            EmployeeManager EmployeeManagerInstance = EmployeeManager::defaultEmployeeManager);

            bool cancelOrder();

            //■■■■■■■■■ default instance ■■■■■■■■■//

            static OrderManager defaultOrderManager;
    };

#endif // ORDER_MANAGER_HPP