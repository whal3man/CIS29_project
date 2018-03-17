#include "../include/Item.h"
#include <iostream>
#include <string>
#include <vector>

const std::vector<Item> Item::possibleItems = {Item("Hunting Rifle", "RANGED WEAPON"), Item("Large Club", "MELEE WEAPON")};// Item("Steel", "MATERIAL"), Item("Leather", "MATERIAL"), Item("Blood Pack", "MATERIAL"), Item("Claw", "MATERIAL"), Item("Gas Container", "MATERIAL"), Item("Leather Strip", "MATERIAL"), Item("Buckles", "MATERIAL"), Item("Small Hilt", "MATERIAL"), Item("Large Hilt", "MATERIAL")};

const std::vector<Item> Item::possibleWeapons = {Item("Hunting Rifle", "RANGED WEAPON"), Item("Large Club", "MELEE WEAPON")};

const std::string defaultWeaponName = "Fists";
const std::string defaultArmorName = "Pants";
// Possible types: WEAPON, RECOVERY, ARMOR, MATERIAL, MISC
// Stats:
// Weapons: ammoCount, baseDamage
Item::Item(std::string itemName_, std::string itemType_, int itemValue_, int sellValue_, int buyValue_)
{
	itemName = itemName_;
	itemType = itemType_;
	itemValue = itemValue_;
	sellValue = sellValue_;
	buyValue = buyValue_;

	damage = 0;
	hpRestore = 0;
	damageResistance = 0;

    if(itemName == "Hunting Rifle")
    {
        itemType = "RANGED WEAPON";
        ammoCount = 20;
        damage = 40;
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
    }
    else if(itemName == "Shortsword")
    {
        itemType = "MELEE WEAPON";
        damage = 45;
    }
    else if(itemName == "Longsword")
    {
        itemType = "MELEE WEAPON";
        damage = 55;
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
    }
    else if(itemName == "Shishkebab")
    {
        itemType = "RECOVERY";
        hpRestore = 30;
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

std::vector<Item> generateLoots(const std::vector<Item>& itemsPool, const double pickRate)
{
    std::vector<Item> loot;
    for (int i = 0; i < itemsPool.size(); i++)
    {
        if (randDouble(0, 1) < pickRate)
        {
            loot.push_back(itemsPool[i]);
        }
    }
    return loot;
}

// Most of the accessor functions have been defined inline in the specification file, since they're very short.

// I'm assuming we're having health points going from 0 - 100. Can scale as project progresses.
//void Item::setHpRestore() {
//	switch(pakType) {
//		case (REGULAR): hpRestore = 20;
//			break;
//		case (SUPER): hpRestore = 40;
//			break;
//		case (ULTRA):  hpRestore = 60;
//		// This kind of stimpak didn't exist in the older games, but I figure we might as well have a third type. <3 - Remy
//			break;
//	}
//}

// I arbitrarily chose these scalars; can be redefined as needed
//void Item::setDamageResistance() {
//	switch(armorType) {
//		case (JUMPSUIT): damageResistance = 0.1;
//			break;
//		case (COMBATARMOR): damageResistance = 0.4;
//			break;
//		case (POWERARMOR): damageResistance = 0.7;
//			break;
//	}
//}
