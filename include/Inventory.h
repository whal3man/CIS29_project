#ifndef INVENTORY_H
#define INVENTORY_H

#include "../include/Item.h"
#include <vector>
#include <iostream>

using namespace std;

class Inventory
{
    public:
        Inventory() {}
        ~Inventory() {}

        vector<Item> items;
        void add(Item obj) { items.push_back(obj); }
        void remove(const Item& obj);
        int getNumItems() { return items.size(); }

        bool containsItems() { return (getNumItems() != 0); }

        bool contains(const Item& obj);

        Item& operator[](int idx) { return items[idx]; }
};

#endif // INVENTORY_H
