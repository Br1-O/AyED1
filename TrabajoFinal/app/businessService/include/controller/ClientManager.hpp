#if !defined(CLIENT_MANAGER_HPP)
#define CLIENT_MANAGER_HPP

    #include <iostream>
    #include <list>

    #include "../model/Client.hpp"

    class ClientManager
    {

        private:

        std::list<Client*> clients;

        public:

            //■■■■■■■■■ getters ■■■■■■■■■//

            //client
            std::list<Client*> getClients() const;

            //■■■■■■■■■ setters ■■■■■■■■■//

            //client
            void setNewClients(Client* client);

            //■■■■■■■■■ constructor ■■■■■■■■■//

            ClientManager();

            ClientManager(            
                std::list<Client*> clients
            );

            //■■■■■■■■■ destructor ■■■■■■■■■//

            ~ClientManager();

            //■■■■■■■■■ methods ■■■■■■■■■//

            void displayClientList();

            Client getClientById(int id);

            Client* loadNewClient();

            //■■■■■■■■■ default instance ■■■■■■■■■//

            static ClientManager defaultClientManager;
    };

#endif // CLIENT_MANAGER_HPP