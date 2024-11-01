#if !defined(ARTICLE_MANAGER_HPP)
#define ARTICLE_MANAGER_HPP

    #include <iostream>
    #include <list>
    #include "./Article.hpp"

    class ArticleManager
    {
        private:

            std::list<Article*> articles;

        public:

            //■■■■■■■■■ getters ■■■■■■■■■//

            //articles
            std::list<Article*> getArticles();

            //■■■■■■■■■ setters ■■■■■■■■■//

            //articles
            void setArticles(std::list<Article*> articles);

            //■■■■■■■■■ constructor ■■■■■■■■■//

            ArticleManager();

            ArticleManager(std::list<Article*> articles);

            //■■■■■■■■■ destructor ■■■■■■■■■//

            ~ArticleManager();

            //■■■■■■■■■ methods ■■■■■■■■■//

            void displayArticleList();
            
            Article* getArticleById(int id);

            Article* loadNewArticle();

            //■■■■■■■■■ default instance ■■■■■■■■■//

            static ArticleManager defaultArticleManager;
            
    };

#endif // ARTICLE_MANAGER_HPP