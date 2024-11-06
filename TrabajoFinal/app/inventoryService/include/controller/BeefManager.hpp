#ifndef BEEFHANDLER_HPP
#define BEEFHANDLER_HPP

    #include <iostream>
    #include <list>
    #include "../model/Beef.hpp"

    class BeefManager
    {
        private:

            std::list<Beef*> inventory;

        public:

            //■■■■■■■■■ getters ■■■■■■■■■//

            //articles
            std::list<Beef*> getInventory() const;

            //■■■■■■■■■ setters ■■■■■■■■■//

            //articles
            void setNewItem(Beef* beefCut);

            //■■■■■■■■■ constructor ■■■■■■■■■//

            BeefManager();

            BeefManager(std::list<Beef*> beefInventory);

            //■■■■■■■■■ destructor ■■■■■■■■■//

            ~BeefManager();

            //■■■■■■■■■ methods ■■■■■■■■■//

            void displayInventoryList() const;
            
            Beef getItemById(int id);

            Beef* loadNewItem();

            //■■■■■■■■■ default instance ■■■■■■■■■//

            static BeefManager defaultBeefManager;
            
    };

#endif // BEEFHANDLER_HPP