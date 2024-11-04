#include <iostream>
#include <string>
#include <list>
#include "../../include/ArticleManager.hpp"
#include "../../include/Article.hpp"
#include "../../include/Utils.hpp"

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
        cout << "Id: " << article->getId() << endl;
        cout << "Nombre: " << article->getName() << endl;
        cout << "Producto: " << article->getPrice() << endl;
        cout << "Unidades en stock: " << article->getUnitsInStock() << endl;
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

    int id, unitsInStock;
    string name;
    double price; 

    Article* newArticle = nullptr;

    cout << "Por favor, ingrese el nombre del nuevo articulo: " << endl;
    getline(cin, name);

    cout << "Ingrese el precio de venta del articulo por unidad: " << endl;
    cin >> price;
    cin.ignore();

    cout << "Ingrese la cantidad de unidades en Stock actualmente: " << endl;
    cin >> unitsInStock;
    cin.ignore();

    try
    {
        //create new id
        list<Article*> currentArticles = ArticleManager::defaultArticleManager.getArticles();

        id = currentArticles.empty() ?
        1
        :
        ((currentArticles.back())->getId()) + 1;

        //generate new article
        newArticle = new Article(id, name, price, unitsInStock);

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

//■■■■■■■■■ default instance ■■■■■■■■■//

ArticleManager ArticleManager::defaultArticleManager;