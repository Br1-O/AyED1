#if !defined(ARTICLE_MANAGER_HPP)
#define ARTICLE_MANAGER_HPP

    #include <iostream>
    #include <list>
    #include "../model/Article.hpp"

    class ArticleManager
    {
        private:

            std::list<Article*> articles;

        public:

            //■■■■■■■■■ getters ■■■■■■■■■//

            //articles
            std::list<Article*> getArticles() const;

            //■■■■■■■■■ setters ■■■■■■■■■//

            //articles
            void setNewArticles(Article* article);

            //■■■■■■■■■ constructor ■■■■■■■■■//

            ArticleManager();

            ArticleManager(std::list<Article*> articles);

            //■■■■■■■■■ destructor ■■■■■■■■■//

            ~ArticleManager();

            //■■■■■■■■■ methods ■■■■■■■■■//

            void displayArticleList() const;
            
            Article getArticleById(int id);

            Article* getArticlePointerById(int id);

            Article* loadNewArticle();

            //■■■■■■■■■ default instance ■■■■■■■■■//

            static ArticleManager defaultArticleManager;
            
    };

#endif // ARTICLE_MANAGER_HPP