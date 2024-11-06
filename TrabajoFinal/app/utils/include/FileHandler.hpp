#if !defined(FILE_HANDLER_HPP)
#define FILE_HANDLER_HPP

    #include <iostream>
    #include <list>
    #include <fstream>
    #include "../../businessService/include/model/Order.hpp"
    #include "../../businessService/include/controller/ArticleManager.hpp"
    #include "../../businessService/include/controller/ClientManager.hpp"
    #include "../../businessService/include/controller/EmployeeManager.hpp"
    #include "../../businessService/include/controller/OrderManager.hpp"

    class FileHandler
    {
        private:

            std::string filePath;
            std::ifstream readFile;
            std::ofstream writeFile;

        public:

            //■■■■■■■■■ getters ■■■■■■■■■//
            
            //file path
            std::string getFilePath() const;

            //■■■■■■■■■ setters ■■■■■■■■■//
            
            //orders
            void setFilePath(std::string filePath);

            //■■■■■■■■■ constructor ■■■■■■■■■//

            FileHandler();

            FileHandler(
            std::string filePath);

            //■■■■■■■■■ destructor ■■■■■■■■■//

            ~FileHandler();

            //■■■■■■■■■ methods ■■■■■■■■■//

            bool loadDataFromFile(std::string filePath = "./data.txt",
            ClientManager* clientManagerInstance = &(ClientManager::defaultClientManager), 
            ArticleManager* articleManagerInstance = &(ArticleManager::defaultArticleManager), 
            EmployeeManager* EmployeeManagerInstance = &(EmployeeManager::defaultEmployeeManager),
            OrderManager* OrderManagerInstance = &(OrderManager::defaultOrderManager)
            );

            bool saveDataIntoFile(std::string filePath = "./data.txt",
            ClientManager clientManagerInstance = ClientManager::defaultClientManager, 
            ArticleManager articleManagerInstance = ArticleManager::defaultArticleManager, 
            EmployeeManager EmployeeManagerInstance = EmployeeManager::defaultEmployeeManager,
            OrderManager OrderManagerInstance = OrderManager::defaultOrderManager);

            //■■■■■■■■■ default instance ■■■■■■■■■//

            static FileHandler defaultFileHandler;
    };

#endif // FILE_HANDLER_HPP