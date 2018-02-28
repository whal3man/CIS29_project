#include "../include/Inventory.h"
#include <algorithm>
#include <iostream>
using namespace std;
Inventory::Inventory()
{

}
Inventory::~Inventory()
{

}
void Inventory::add(Item obj)
{
    items.push_back(obj);
    if(obj.getItemName() == "healthKit")
        healthKitNum++;
}
void Inventory::remove(string name)
{
    //if there is more than one health kit than it removes the first one that it finds
    for(int a = 0; a < items.size();a++)
    {
        if(items[a].getItemName() == name)
        {
            if(items[a].getItemName() == "healthKit")
                healthKitNum--;
            items.erase(items.begin() + a);
            break;
        }
    }
}
void Inventory::display()
{
        cout<<"Health Kit: "<<healthKitNum<<endl;
}
