#include "Inventory.h"
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
    vec.push_back(obj);
    if(obj.getItemName() == "healthKit")
        healthKitNum++;
}
void Inventory::removing(string name)
{
    //if there is more than one health kit than it removes the first one that it finds
    for(int a = 0; a < vec.size();a++)
    {
        if(vec[a].getItemName() == name)
        {
            if(obj.getItemName() == "healthKit")
                healthKitNum--;
            vec.erase(remove(vec.begin(), vec.end(), a), vec.end());
            break;
        }
    }
}
void Inventory::display()
{
        cout<<"Health Kit: "<<healthKitNum<<endl;
}
void Inventory::use(string name)
{
        for(int a = 0; a < vec.size(); a++)
        {
            if(vec[a].getItemName() == name)
            {
                //Assuming the player has a maximum of hp of 100 and the health kit is worth 20
                removing(name);
                int hp = getHP();
                if(hp <= 80 && hp >= 1)//the players hp cant be not less than or equal to 0
                    hp = hp + 20;
                if(hp >= 81 && hp >= 100)
                    hp = 100 - hp;
                setHP(hp);
            }
        }
}
