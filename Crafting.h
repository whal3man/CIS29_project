//
//  crafting.h
//  crafting
//
//  Created by Lukas Pettersson on 2/20/18.
//  Copyright © 2018 Lukas Pettersson. All rights reserved.
//
//*******************************************************************************************
//IMPORTANT NOTICE WE NEED TO ADD THE ATTTRIBUTES OF THE ITEMS THAT ARE GOING TO BE CREATED IN THE CLASSES
//IMPORTNANT WE NEED TO ADD A FUNCTION TO SEE IF THERE ARE INTEMS IN THE INVENTORY
//********************************************************************************************

#ifndef crafting_h
#define crafting_h
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Inventory.h"
class craftedItem: public Item, public Inventory
{
private:

public:
    void craftStimpak()
    {
        Item Stimpak{};//create an item object with stats of a stimpak
        if ()
        {
            Inventory::remove("Steel");
            Iventory::remove("Blood Pack");
            Inventory::add(Stimpak);
        }
        else
        {
            cout << "You do not have the items to craft that.\n";
        }
    void craftDeathClawGauntlet()
    {
        Item DeathClawGauntlet{};//create an item object with stats of a stimpak
       if ()
       {
           Inventory::remove("Leather");
           Inventory::remove("Steel");
           Inventory::remove("Claw");
           Inventory::add(DeathClawGauntlet);
       }
       else
       {
           cout << "You do not have the items to craft a deathclawgauntlet.\n";
       }
    }
    void craftShishKebab()
    {
        Item ShishKebab{};//create an item object with stats of a stimpak
        if()
        {
            Inventory::remove("Steel");
            Inventory::remove("Leather");
            Inventory::remove("GasContainer");
            Inventory::add(ShishKebab);
        }
        else
        {
            cout << "You do not have the items to craft a shish kebab.\n";
        }
    }
        
    void shortSword()
    {
            Item ShortSword{};//create an item object with stats of a stimpak
            if()
            {
                Inventory::remove("Steel");
                Inventory::remove("Leather");
                Inventory::add(ShortSword);
            }
            else
            {
                cout << "You do not have the items to craft short sword.\n";
            }
    }
    void LongSword()
        {
            Item LongSword{};//create an item object with stats of a stimpak
            if()
            {
                Inventory::remove("Steel");
                Inventory::remove("Leather");
                Inventory::add(ShortSword);
            }
            else
            {
                cout << "You do not have the items to craft a long sword.\n";
            }
        }
    void craftLightArmor()
        {
            Item LightArmor{};//create an item object with stats of a stimpak
            if() //the items that are being removed are in the inventory
            {
                Inventory::remove("Steel");
                Inventory::remove("Leather");
                Inventory::add(ShortSword);
            }
            else
            {
                cout << "You do not have the items to craft light armor.\n";
            }
        }
    void craftHeavyArmor()
        {
            Item HeavyArmor{};//create an item object with stats of a stimpak
            if() //the items that are being removed are in the inventory
            {
                Inventory::remove("Steel");
                Inventory::remove("Leather");
                Inventory::add(HeavyArmor);
            }
            else
            {
                cout << "You do not have the items to craft heavy armor.\n";
            }
        }
};

#endif /* crafting_h */
