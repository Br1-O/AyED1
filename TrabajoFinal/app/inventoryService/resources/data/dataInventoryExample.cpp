#include <iostream>
#include <list>
#include "./dataInventoryExample.hpp"
#include "../../include/controller/MeatManager.hpp"
#include "../../include/model/MeatProduct.hpp"
#include "../../include/model/Beef.hpp"
#include "../../include/model/Chicken.hpp"
#include "../../include/model/Pork.hpp"
#include "../../../businessService/include/model/Article.hpp"
#include "../../../businessService/include/controller/ArticleManager.hpp"
#include "../../../utils/include/Date.hpp"

namespace dataInventoryExample
{
    void loadData()
    {
        try
        {
            //create beef instance
            Beef* newBeefCut = new Beef(1, 1200, "Nalga", 4, 'C', 20, 
            Date(20, 10, 2024), Date(30, 10, 2024), 1, 1, 1);
            
            //create chicken instance
            Chicken* newChickenCut = new Chicken(2, 1000, "Pata muslo", 4, 'C', 10, 
            Date(25, 10, 2024), Date(05, 10, 2024), 2, 2, 'B');
            
            //create pork instance
            Pork* newPorkCut = new Pork(3, 800, "Pechito de cerdo", 4, 'C', 30, 
            Date(25, 10, 2024), Date(05, 10, 2024), 3, 3, 2);

            //save via into manager class
            MeatManager::defaultMeatManager.setNewItem(newBeefCut);
            MeatManager::defaultMeatManager.setNewItem(newChickenCut);
            MeatManager::defaultMeatManager.setNewItem(newPorkCut);

            //get meat from meat list
            Meat* beef = MeatManager::defaultMeatManager.getItemById(1);
            Meat* chicken = MeatManager::defaultMeatManager.getItemById(2);
            Meat* pork = MeatManager::defaultMeatManager.getItemById(3);

            //generate new meat product
            Article* newArticle = new MeatProduct(1, "Milanesas de carne", 2000, 20, beef, 0.75);
            Article* newArticle2 = new MeatProduct(2, "Milanesas de pollo", 5000, 10, chicken, 0.75);
            Article* newArticle3 = new MeatProduct(3, "Pechito de cerdo", 3500, 5, pork, 1);

            //create into articles list inside default Article Manager Instance
            ArticleManager::defaultArticleManager.setNewArticles(newArticle);
            ArticleManager::defaultArticleManager.setNewArticles(newArticle2);
            ArticleManager::defaultArticleManager.setNewArticles(newArticle3);

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';

            std::cout << "¡No se pudo cargar el listado correctamente por esta razon!" << std::endl << std::endl;
        }
    }
} // namespace dataExample