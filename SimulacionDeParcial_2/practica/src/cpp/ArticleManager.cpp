#include <iostream>
#include <string>
#include <list>
#include "../../include/ArticleManager.hpp"
#include "../../include/Article.hpp"
#include "../../include/Utils.hpp"

using namespace std;

//■■■■■■■■■ getters ■■■■■■■■■//

//articles
list<Article*> ArticleManager::getArticles(){
    return this->articles;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//articles
void ArticleManager::setArticles(list<Article*> articles){
    this->articles = articles;
};

//■■■■■■■■■ constructor ■■■■■■■■■//

ArticleManager::ArticleManager(){};

ArticleManager::ArticleManager(list<Article*> articles){
    this->articles = articles;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

ArticleManager::~ArticleManager(){
    for (Article* article: ArticleManager::articles)
    {
        delete article;
    }
    articles.clear();
};

//■■■■■■■■■ methods ■■■■■■■■■//

void ArticleManager::displayArticleList(){

    list<Article*> currentArticles = ArticleManager::getArticles();

    string title = "Listado de productos: ";
    string lineSeparator =  "---------------------------------";

    cout << title << endl;

    for (Article* article:currentArticles)
    {
        cout << lineSeparator << endl;
        cout << "Id: " << article->getId() << endl;
        cout << "Nombre: " << article->getName() << endl;
        cout << "Producto: " << article->getPrice() << endl;
        cout << "Unidades en stock: " << article->getUnitsInStock() << endl;
        cout << lineSeparator << endl;
    }

    cout << endl;

    utils::pauseConsole();
};

Article* ArticleManager::getArticleById(int id){

    Article* searchedArticle = nullptr;

    list<Article*> currentArticles = ArticleManager::getArticles();

    for (Article* article : currentArticles)
    {
        if (id == (article->getId()))
        {
            searchedArticle = article;
            break;
        }
    }

    return searchedArticle;
};

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
        list<Article*> currentArticles = ArticleManager::getArticles();

        id = currentArticles.empty() ?
        1
        :
        ((currentArticles.back())->getId()) + 1;

        //generate new article
        newArticle = new Article(id, name, price, unitsInStock);

        //push it into articles list
        currentArticles.push_back(newArticle);

        //save it into manager class
        ArticleManager::setArticles(currentArticles);

        cout << "¡Articulo agregado correctamente!" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "¡No se ha podido crear el nuevo articulo por esta razon!";
        if(newArticle) delete newArticle;
    }

    return newArticle;
};