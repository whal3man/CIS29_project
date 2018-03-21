#include "../include/Item.h"
#include <iostream>
#include <string>
#include <vector>

const std::vector<Item> Item::possibleItems = {Item("Hunting Rifle"), Item("Large Club"), Item("DeathClaw Gauntlet"), Item("Shortsword"), Item("Longsword"), Item("Light Armor"), Item("Heavy Armor"), Item("Stimpak"), Item("Shishkebab"), Item("Apple"), Item("Blood Pack"), Item("Steel"), Item("Leather")};

const std::vector<Item> Item::possibleWeapons = {Item("Hunting Rifle"), Item("Large Club"), Item("DeathClaw Gauntlet"), Item("Shortsword"), Item("Longsword")};

const std::string defaultWeaponName = "Fists";
const std::string defaultArmorName = "Pants";
// Possible types: WEAPON, RECOVERY, ARMOR, MATERIAL, MISC
// Stats:
// Weapons: ammoCount, baseDamage
Item::Item(std::string itemName_, std::string itemType_, int itemValue_)
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
	itemValue = 100;
    }
    else if(itemName == "Mini Nuke")
    {
        itemType = "RANGED WEAPON";
        ammoCount = 5;
        damage = 100;
	itemValue = 200;
    }
    else if (itemName == "Molotov Bomb")
    {
	itemType = "RANGED WEAPON";
	ammoCount = 10;
	damage = 25;
	itemValue = 20;
    }
    else if(itemName == "Large Club")
    {
        itemType = "MELEE WEAPON";
        damage = 20;
	itemValue = 20;
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
	itemValue = 55;
    }
    else if(itemName == "Longsword")
    {
        itemType = "MELEE WEAPON";
        damage = 55;
        itemValue = 70;
    }
    else if(itemName == "Light Armor")
    {
        itemType = "ARMOR";
        damageResistance = 30;
	    itemValue = 50;
    }
    else if(itemName == "Heavy Armor")
    {
        itemType = "ARMOR";
        damageResistance = 40;
	    itemValue = 100;
    }
	else if (itemName == "Potion")
		{
			itemType = "RECOVERY";
			hpRestore = 20;
			itemValue = 15;
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
	    itemValue = 50;
    }
    else if(itemName == "Leather")
    {
        itemType = "MATERIAL";
	    itemValue = 50;
    }
    else if(itemName == "Stick")
    {
        itemType = "MATERIAL";
    }
    else if(itemName == "Buckles")
    {
        itemType = "MATERIAL";
    }
    else if (itemName == "GasContainer")
    {
	itemType = "MATERIAL";
	itemValue = 20;
    }
    else if (itemName == "Claw")
    {
	itemType = "MATERIAL";
	itemValue = 10;
    }
    else if (itemName == "Ruby")
    {
	itemType = "MATERIAL";
	itemValue = 100;
    }
    else if (itemName == "Wizard Gem")
	{
		itemType = "MATERIAL";
		itemValue = 100;
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
