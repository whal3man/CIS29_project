#ifndef INVENTORY_H
#define INVENTORY_H

#include "../include/Item.h"
#include <vector>
#include <iostream>

using namespace std;

class Inventory
{
    public:
        vector<Item> items;
        int healthKitNum;

        Inventory();
        ~Inventory();
        void add(Item obj);
        void remove(string name);
        void display();
        void use(string name);

};

#endif // INVENTORY_H
