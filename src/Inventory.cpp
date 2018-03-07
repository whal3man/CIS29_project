#include "../include/Inventory.h"
#include <algorithm>
#include <iostream>
using namespace std;

void Inventory::remove(const Item& obj)
{
    //if there is more than one health kit than it removes the first one that it finds
    auto idx = find(items.begin(), items.end(), obj);
    if(idx != items.end()) items.erase(idx);
}

bool Inventory::contains(const Item& obj)
{
    auto idx = find(items.begin(), items.end(), obj);
    if(idx != items.end()) return true;
    return false;
}
