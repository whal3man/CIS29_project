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
    int caps;

    Inventory() : caps(0) {}
    ~Inventory() {}

    int getCaps() const { return caps; }
    void setCaps(int c) { caps = c; }
    void addCaps(int c) { caps += c; }
    void subCaps(int c) { caps -= c; }

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
    int count(const Item& item);

    void craft(const std::string& itemName);
    string getCraftingChoice();

    int size()
    {
        return items.size();
    }

    Item& operator[](int idx)
    {
        return items[idx];
    }
};

#endif // INVENTORY_H
