#include <iostream>
#include <list>
#include "./data.hpp"
#include "../../include/ArticleManager.hpp"
#include "../../include/ClientManager.hpp"
#include "../../include/OrderManager.hpp"

namespace data
{
    void loadData()
    {
        try
        {
            Client* client1 = new Client(1, "Juan", "Perez", "555-1234", "123 Elm St, Madrid");
            Client* client2 = new Client(2, "Maria", "Gomez", "555-5678", "456 Oak St, Barcelona");
            Client* client3 = new Client(3, "Carlos", "Lopez", "555-9012", "789 Pine St, Valencia");

            ClientManager::defaultClientManager.setNewClients(client1);
            ClientManager::defaultClientManager.setNewClients(client2);
            ClientManager::defaultClientManager.setNewClients(client3);


            Article* article1 = new Article(1, "Laptop", 1000.0, 20);
            Article* article2 = new Article(2, "Smartphone", 500.0, 50);
            Article* article3 = new Article(3, "Headphones", 200.0, 30);
            Article* article4 = new Article(4, "Smartwatch", 250., 15);
            Article* article5 = new Article(5, "Tablet", 350.0, 25);

            ArticleManager::defaultArticleManager.setNewArticles(article1);
            ArticleManager::defaultArticleManager.setNewArticles(article2);
            ArticleManager::defaultArticleManager.setNewArticles(article3);
            ArticleManager::defaultArticleManager.setNewArticles(article4);
            ArticleManager::defaultArticleManager.setNewArticles(article5);


            std::list<Article> articlesOrder1;

            article1->setQuantity(1);
            article2->setQuantity(2);
            articlesOrder1.push_back(*(article1));
            articlesOrder1.push_back(*(article2));

            Order* order1 = new Order(1, *client1, articlesOrder1, 2000);

            std::list<Article> articlesOrder2;

            article3->setQuantity(5);
            article4->setQuantity(1);
            articlesOrder2.push_back(*(article3));
            articlesOrder2.push_back(*(article4));

            Order* order2 = new Order(2, *client2, articlesOrder2, 1250);

            OrderManager::defaultOrderManager.setNewOrders(order1);
            OrderManager::defaultOrderManager.setNewOrders(order2);

            std::cout << "¡Listado agregado correctamente!" << std::endl << std::endl;

            std::cout << "Clientes cargados: " << ClientManager::defaultClientManager.getClients().size() << std::endl;
            std::cout << "Articulos cargados: " << ArticleManager::defaultArticleManager.getArticles().size() << std::endl;
            std::cout << "Ordenes cargadas: " << OrderManager::defaultOrderManager.getOrders().size() << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';

            std::cout << "¡No se pudo cargar el listado correctamente por esta razon!" << std::endl << std::endl;
        }
    }
} // namespace data
