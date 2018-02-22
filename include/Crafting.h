//
//  crafting.h
//  crafting
//
//  Created by Lukas Pettersson on 2/20/18.
//  Copyright © 2018 Lukas Pettersson. All rights reserved.
//
//************************************************************************************************************************
//IMPORTANT NOTICE WE NEED TO ADD THE NAMES OF THE OBJECTS THAT ARE GOING TO BE REMOVED FROM INVENTORY
//IMPORTANT NOTICE WENEED TO ADD THE ATTTRIBUTES OF THE ITEMS THAT ARE GOING TO BE CREATED IN THE CLASSES
//************************************************************************************************************************

#ifndef crafting_h
#define crafting_h
#include <iostream>
#include <string>
#include <vector>
#include "item.h"
#include "Inventory.h"
class craftedItem: public Item, public Inventory
{
private:
   
public:
    void UI()
    {
        string i;
        cout << "hello welcome to your personalized crafting station\n";
        cout << "what would you like to craft today?\n";
        cout << "if you wouldn't like to craft anything you can write 'EXIT' in the line below...\n";
        cin >> i;
        if(i == "stimpak")
        {
            craftStimpak();
        }
        else if(i == "deathclaw gauntlet")
        {
            craftDeathClawGauntlet();
        }
        else if (i == "shish kebab")
        {
            
        }
        
    }
    void craftStimpak()
    {
        Item Stimpak{};//create an item object with stats of a stimpak
        Inventory::removing(""); //remove two items that are in the inventory these are strings that will be
        Inventory::removing("");
        
        Inventory::add(Stimpak); // add the new item into the inventory
    }
    void craftDeathClawGauntlet()
    {
        Item DeathClawGauntlet{};//create an item object with stats of a stimpak
        Inventory::removing("");
        Inventory::removing("");
        
        Inventory::add(DeathClawGauntlet);
    }
    void craftShishKebab()
    {
        Item ShishKebab{};//create an item object with stats of a stimpak
        
        Inventory::removing("");
        Inventory::removing("");
        
        Inventory::add(ShishKebab);
    }
    void shortSword()
    {
        Item shortSword{};//create an item object with stats of a stimpak
        
        Inventory::removing("");
        Inventory::removing("");
        
        Inventory::add(shortSword);
    }
    void longSword()
    {
        Item longSword{};//create an item object with stats of a stimpak
        
        Inventory::removing("");
        Inventory::removing("");
        
        Inventory::add(longSword);
    }
    void craftLightArmor()
    {
        Item LightArmor{};//create an item object with stats of a stimpak
        
        Inventory::removing("");
        Inventory::removing("");
        
        Inventory::add(LightArmor);
    }
    void craftHeavyArmor()
    {
        Item HeavyArmor{};//create an item object with stats of a stimpak
        
        Inventory::removing("");
        Inventory::removing("");
        
        Inventory::add(HeavyArmor);
    }
};

#endif /* crafting_h */
