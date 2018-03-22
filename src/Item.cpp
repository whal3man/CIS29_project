#include "../include/Item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<Item> Item::possibleItems = {Item("Hunting Rifle"), Item("Large Club"), Item("DeathClaw Gauntlet"), Item("Shortsword"), Item("Longsword"), Item("Light Armor"), Item("Heavy Armor"), Item("Stimpak"), Item("Shishkebab"), Item("Apple"), Item("Blood Pack"), Item("Steel"), Item("Leather")};

const vector<Item> Item::possibleWeapons = {Item("Hunting Rifle"), Item("Large Club"), Item("DeathClaw Gauntlet"), Item("Shortsword"), Item("Longsword")};

const string defaultWeaponName = "Fists";
const string defaultArmorName = "Pants";
// Possible types: WEAPON, RECOVERY, ARMOR, MATERIAL, MISC
// Stats:
// Weapons: ammoCount, baseDamage
Item::Item(string itemName_, string itemType_, int itemValue_)
{
    itemName = itemName_;
    itemType = itemType_;
    itemValue = itemValue_;

    damage = 0;
    hpRestore = 0;
    damageResistance = 0;

    if(itemName == "Hunting Rifle")
    {
        itemType = "RANGED WEAPON";
        ammoCount = 20;
        damage = 30;
    }
    else if(itemName == "Mini Nuke")
    {
        itemType = "RANGED WEAPON";
        ammoCount = 5;
        damage = 100;
    }
    else if(itemName == "Large Club")
    {
        itemType = "MELEE WEAPON";
        damage = 20;
    }
    else if(itemName == "DeathClaw Gauntlet")
    {
        itemType = "MELEE WEAPON";
        damage = 60;
        itemValue = 50;
    }
    else if(itemName == "Shortsword")
    {
        itemType = "MELEE WEAPON";
        damage = 35;
    }
    else if(itemName == "Longsword")
    {
        itemType = "MELEE WEAPON";
        damage = 55;
        itemValue = 40;
    }
    else if(itemName == "Light Armor")
    {
        itemType = "ARMOR";
        damageResistance = 30;
    }
    else if(itemName == "Heavy Armor")
    {
        itemType = "ARMOR";
        damageResistance = 40;
    }
    else if(itemName == "Stimpak")
    {
        itemType = "RECOVERY";
        hpRestore = 50;
        itemValue = 30;
    }
    else if(itemName == "Shishkebab")
    {
        itemType = "RECOVERY";
        hpRestore = 30;
    }
    else if(itemName == "Apple")
    {
        itemType = "RECOVERY";
        hpRestore = 15;
        itemValue = 15;
    }
    else if(itemName == "Blood Pack")
    {
        itemType = "MATERIAL";
    }
    else if(itemName == "Steel")
    {
        itemType = "MATERIAL";
    }
    else if(itemName == "Leather")
    {
        itemType = "MATERIAL";
    }
    else if(itemName == "Stick")
    {
        itemType = "MATERIAL";
    }
    else if(itemName == "Buckles")
    {
        itemType = "MATERIAL";
    }
    else if(itemName == "Claw")
    {
        itemType = "MATERIAL";
    }
    else if(itemName == defaultWeaponName)
    {
        itemType = "MELEE WEAPON";
        damage = 10;
    }
    else if(itemName == defaultArmorName)
    {
        itemType = "ARMOR";
        damageResistance = 0;
    }
}

Item::~Item()
{

}
