#ifndef MEATHANDLER_HPP
#define MEATHANDLER_HPP

#include <iostream>
#include <list>
#include "../model/Meat.hpp"

class MeatManager
{
private:
    std::list<Meat*> inventory;  // Store pointers to Meat objects (and its derived classes)

public:
    //■■■■■■■■■ getters ■■■■■■■■■//

    // Returns the inventory list of meats
    std::list<Meat*> getInventory() const;

    //■■■■■■■■■ setters ■■■■■■■■■//

    // Adds a new meat item to the inventory
    void setNewItem(Meat* meatCut);

    //■■■■■■■■■ constructor ■■■■■■■■■//

    MeatManager();  // Default constructor
    MeatManager(std::list<Meat*> meatInventory);  // Constructor with an inventory

    //■■■■■■■■■ destructor ■■■■■■■■■//

    ~MeatManager();  // Destructor

    //■■■■■■■■■ methods ■■■■■■■■■//

    // Display the entire inventory of meat items
    void displayInventoryList() const;

    // Get a meat item by its ID
    Meat* getItemById(int id);

    // Load a new meat item
    Meat* loadNewItem();

    //■■■■■■■■■ default instance ■■■■■■■■■//

    static MeatManager defaultMeatManager;  // Static instance for convenience
};

#endif // MEATHANDLER_HPP
