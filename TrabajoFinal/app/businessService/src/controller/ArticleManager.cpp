#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include "../../include/model/Article.hpp"
#include "../../include/controller/ArticleManager.hpp"
#include "../../../utils/include/Utils.hpp"

#include "../../../inventoryService/include/model/MeatProduct.hpp"
#include "../../../inventoryService/include/controller/MeatManager.hpp"

using namespace std;

//■■■■■■■■■ getters ■■■■■■■■■//

//articles
list<Article*> ArticleManager::getArticles() const{
    return this->articles;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//articles
void ArticleManager::setNewArticles(Article* article){
    (this->articles).push_back(article);
};

//■■■■■■■■■ constructor ■■■■■■■■■//

ArticleManager::ArticleManager(){};

ArticleManager::ArticleManager(list<Article*> articles){
    this->articles = articles;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

ArticleManager::~ArticleManager(){

    //since my Manager classes are singletons, which are suppose to live through the whole app lifetime they don't implement a default destructor

};

//■■■■■■■■■ methods ■■■■■■■■■//

void ArticleManager::displayArticleList() const {

    list<Article*> currentArticles = ArticleManager::defaultArticleManager.getArticles();

    string title = "Listado de productos: ";
    string lineSeparator =  "---------------------------------";

    cout << title << endl;

    for (const auto &article :currentArticles)
    {
        cout << lineSeparator << endl;

        //apply polimorph to display article info
        article->displayInfo();

        cout << lineSeparator << endl;
    }

    cout << endl;
};

Article ArticleManager::getArticleById(int id) {
    Article foundArticle;
    foundArticle.setId(0);

    const auto& currentArticles = ArticleManager::defaultArticleManager.getArticles();

    for (const auto& article : currentArticles) {
        if (id == article->getId()) {
            foundArticle = *article;
        }
    }

    return foundArticle;
}

Article* ArticleManager::loadNewArticle(){

    int isMeatProduct = 0;

    int id, unitsInStock;
    string name;
    double price; 

    int meatId;
    string relationOfPortionWithRawMaterialInput;
    float relationOfPortionWithRawMaterial = 1.0; //temporarily hardcoded

    Article* newArticle = nullptr;

    cout << "El producto a ingresar es una carne o un derivado carnico?" << endl << " 0 = No | 1 = Si  " << endl;
    cin >> isMeatProduct;
    cin.ignore();

    if (isMeatProduct == 1)
    {      
        cout << "Por favor, ingrese el nombre del nuevo producto: " << endl;
        getline(cin, name);

        cout << "Ingrese el precio de venta del producto por kg: " << endl;
        cin >> price;
        cin.ignore();

        cout << "Ingrese la cantidad en Stock actualmente: (en kg, sin decimales)" << endl;
        cin >> unitsInStock;
        cin.ignore();

        cout << "Ingrese el id del tipo de carne a usarse para crear este producto: " << endl;
        cin >> meatId;
        cin.ignore();
    }else
    {
        cout << "Por favor, ingrese el nombre del nuevo articulo: " << endl;
        getline(cin, name);

        cout << "Ingrese el precio de venta del articulo por unidad: " << endl;
        cin >> price;
        cin.ignore();

        cout << "Ingrese la cantidad de unidades en Stock actualmente:" << endl;
        cin >> unitsInStock;
        cin.ignore();
    }
    
    try
    {
        //create new id
        list<Article*> currentArticles = ArticleManager::defaultArticleManager.getArticles();

        id = currentArticles.empty() ?
        1
        :
        ((currentArticles.back())->getId()) + 1;

        if (isMeatProduct == 1)
        {
            //get meat from meat list
            Meat* meat = MeatManager::defaultMeatManager.getItemById(meatId);

            //generate new meat product
            newArticle = new MeatProduct(id, name, price, unitsInStock, meat, relationOfPortionWithRawMaterial);

        }else{
            //generate new article
            newArticle = new Article(id, name, price, unitsInStock);
        }

        //save it into manager class
        ArticleManager::defaultArticleManager.setNewArticles(newArticle);

        cout << endl << "Articulo agregado correctamente." << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "No se ha podido crear el nuevo articulo por esta razon.";
        if(newArticle) delete newArticle;
    }

    return newArticle;
};

Article* ArticleManager::getArticlePointerById(int id)
{
    Article* foundArticle = nullptr;
    const auto& currentArticles = ArticleManager::defaultArticleManager.getArticles();
    
    for (const auto& article : currentArticles) {
        if (id == article->getId()) {
            foundArticle = article;
        }
    }
    
    return foundArticle;
}
//■■■■■■■■■ default instance ■■■■■■■■■//

ArticleManager ArticleManager::defaultArticleManager;