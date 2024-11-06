#ifndef CHICKENHANDLER_HPP
#define CHICKENHANDLER_HPP

#include <iostream>
#include <list>
#include "../model/Chicken.hpp"

class ChickenManager {
    private:
        std::list<Chicken*> inventory;

    public:
        //■■■■■■■■■ getters ■■■■■■■■■//

        // inventory
        std::list<Chicken*> getInventory() const;

        //■■■■■■■■■ setters ■■■■■■■■■//

        // inventory
        void setNewItem(Chicken* chickenCut);

        //■■■■■■■■■ constructor ■■■■■■■■■//

        ChickenManager();
        ChickenManager(std::list<Chicken*> chickenInventory);

        //■■■■■■■■■ destructor ■■■■■■■■■//

        ~ChickenManager();

        //■■■■■■■■■ methods ■■■■■■■■■//

        void displayInventoryList() const;
        Chicken getItemById(int id);
        Chicken* loadNewItem();

        //■■■■■■■■■ default instance ■■■■■■■■■//

        static ChickenManager defaultChickenManager;
};

#endif // CHICKENHANDLER_HPP