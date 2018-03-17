#ifndef INVENTORY_H
#define INVENTORY_H

#include "../include/Item.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Inventory
{
public:
    Inventory() {}
    ~Inventory() {}

    vector<Item> items;
    void add(Item obj)
    {
        items.push_back(obj);
    }
    void remove(const Item& obj);
    void remove(const string& name);
    int getNumItems()
    {
        return items.size();
    }

    bool containsItems()
    {
        return (getNumItems() != 0);
    }

    bool contains(const Item& obj);
    bool contains(const string& name);

    void craft(const std::string& itemName);
    string getCraftingChoice();

    Item& operator[](int idx)
    {
        return items[idx];
    }
};

#endif // INVENTORY_H
