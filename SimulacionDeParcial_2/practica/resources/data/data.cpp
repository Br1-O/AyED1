#include <list>
#include "../../include/ArticleManager.hpp"
#include "../../include/ClientManager.hpp"

bool loadData()
{
    std::list<Client*> defaultClients;
    std::list<Article*> defaultArticles;

    Client* client1 = new Client(1, "Juan", "Perez", "555-1234", "123 Elm St, Madrid");
    Client* client2 = new Client(2, "Maria", "Gomez", "555-5678", "456 Oak St, Barcelona");
    Client* client3 = new Client(3, "Carlos", "Lopez", "555-9012", "789 Pine St, Valencia");

    defaultClients.push_back(client1);
    defaultClients.push_back(client2);
    defaultClients.push_back(client3);

    ClientManager::defaultClientManager.setClients(defaultClients);

    Article* article1 = new Article(1, "Laptop", 999.99, 20);
    Article* article2 = new Article(2, "Smartphone", 499.99, 50);
    Article* article3 = new Article(3, "Headphones", 199.99, 30);
    Article* article4 = new Article(4, "Smartwatch", 249.99, 15);
    Article* article5 = new Article(5, "Tablet", 349.99, 25);

    defaultArticles.push_back(article1);
    defaultArticles.push_back(article2);
    defaultArticles.push_back(article3);
    defaultArticles.push_back(article4);
    defaultArticles.push_back(article5);

    ArticleManager::defaultArticleManager.setArticles(defaultArticles);
}