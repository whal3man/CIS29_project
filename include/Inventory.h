#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <iostream>

using namespace std;

class Inventory: public Character
{
    private:
        vector<Item> vec;
        int healthKitNum;

    public:
        Inventory();
        ~Inventory();
        void add(Item obj);
        void removing(string name);
        void display();
        void use(string name);

};

#endif // INVENTORY_H
