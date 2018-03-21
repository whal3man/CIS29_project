#include "../include/Inventory.h"
#include "../include/Commands.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

void Inventory::remove(const Item& obj)
{
    //if there is more than one health kit than it removes the first one that it finds
    auto idx = find(items.begin(), items.end(), obj);
    if(idx != items.end())
        items.erase(idx);
}

// Removes one instance of an item
void Inventory::remove(const std::string& name)
{
    int i = 0;
    for(auto item : items)
    {
        if(item.itemName == name)
        {
            items.erase(items.begin() + i);
            return;
        }
        i++;
    }
}

// Returns the count of an item
int Inventory::count(const Item& item)
{
    int c = 0;
    for(auto potential : items)
    {
        if(potential == item) c++;
    }
    return c;
}

bool Inventory::contains(const Item& obj)
{
    auto idx = find(items.begin(), items.end(), obj);
    if(idx != items.end())
        return true;
    return false;
}

bool Inventory::contains(const std::string& name)
{
    for(auto item : items)
    {
        if(item.itemName == name)
            return true;
    }
    return false;
}

void Inventory::craft(const std::string& itemName)
{
    if(itemName == "Stimpak")
    {
        if (contains("Steel") && contains("Blood Pack"))
        {
            remove("Steel");
            remove("Blood Pack");
            add(Item("Stimpak"));
        }
        else
        {
            std::cout << "You do not have the items to craft a Stimpak.\n";
            system(pauseCommand.c_str());
        }
    }
    else if(itemName == "DeathClaw Gauntlet")
    {
        if (contains("Leather") && contains("Steel") && contains("Claw"))
        {
            remove("Leather");
            remove("Steel");
            remove("Claw");
            add(Item("DeathClaw Gauntlet"));
        }
        else
        {
            cout << "You do not have the items to craft a Deathclaw Gauntlet.\n";
            system(pauseCommand.c_str());
        }
    }
    else if(itemName == "Shishkebab")
    {
        if(contains("Steel") && contains("Leather"))
        {
            remove("Steel");
            remove("Leather");
            add(Item("Shishkebab"));
        }
        else
        {
            cout << "You do not have the items to craft a Shishkebab.\n";
            system(pauseCommand.c_str());
        }
    }
    else if(itemName == "Shortsword")
    {
        Item ShortSword{};//create an item object with stats of a stimpak
        if(contains("Steel") && contains("Leather"))
        {
            remove("Steel");
            remove("Leather");
            add(Item("Shortsword"));
        }
        else
        {
            cout << "You do not have the items to craft a Shortsword.\n";
            system(pauseCommand.c_str());
        }
    }
    else if(itemName == "Longsword")
    {
        if(contains("Steel") && contains("Leather"))
        {
            remove("Steel");
            remove("Leather");
            add(Item("Longsword"));
        }
        else
        {
            cout << "You do not have the items to craft a Longsword.\n";
            system(pauseCommand.c_str());
        }
    }
    else if(itemName == "Light Armor")
    {
        if(contains("Steel") && contains("Leather")) //the items that are being removed are in the inventory
        {
            remove("Steel");
            remove("Leather");
            add(Item("Light Armor"));
        }
        else
        {
            cout << "You do not have the items to craft Light Armor.\n";
            system(pauseCommand.c_str());
        }
    }
    else if(itemName == "Heavy Armor")
    {
        if(contains("Steel") && contains("Leather")) //the items that are being removed are in the inventory
        {
            remove("Steel");
            remove("Leather");
            add(Item("Heavy Armor"));
        }
        else
        {
            cout << "You do not have the items to craft Heavy Armor.\n";
            system(pauseCommand.c_str());
        }
    }
    else if(itemName != "e")
    {
        cout << "Crafting recipe not found.\n";
        system(pauseCommand.c_str());
    }
}

string Inventory::getCraftingChoice()
{
    system(clsCommand.c_str());
    string option;
    cout << "List of items that can be crafted: " <<endl;
    cout <<setw(20)<<left <<"ITEM"<<setw(5) <<"|" << "REAGENTS NEEDED" <<setw(10)<<endl;
    cout << "-----------------------------------------------------------------------------\n";
    cout <<setw(20)<<left <<"Stimpak"<<setw(5) <<"|" << "Blood Pack , Steel" <<endl;
    cout <<setw(20)<< left<<"DeathClaw Gauntlet"<<setw(5) <<"|" << "Leather , Steel , Claw" <<endl;
    cout <<setw(20)<< left<<"Shishkebab"<<setw(5) <<"|" << "Steel , Leather" <<endl;
    cout <<setw(20)<< left<<"Shortsword"<<setw(5) <<"|" << "Steel, Leather" <<endl;
    cout <<setw(20)<< left<<"Longsword"<<setw(5) <<"|" << "Steel , Leather" <<endl;
    cout <<setw(20)<< left<<"Light Armor"<<setw(5) <<"|" << "Leather , Buckles" <<endl;
    cout <<setw(20)<< left<<"Heavy Armor"<<setw(5) <<"|" << "Steel , Buckles" <<endl;

    cout << "\nWhat would you like to craft? (Type e to exit) \n" <<endl;
    cin >> option;

    return option;
}
