#include "../include/Item.h"
#include <iostream>

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

	if(itemType == "RANGED WEAPON")
    {
        if(itemName == "Hunting Rifle")
        {
            ammoCount = 20;
            damage = 30;
        }
    }
    else if(itemType == "MELEE WEAPON")
    {
        if(itemName == "Large Club")
        {
            damage = 20;
        }
    }
}

Item::~Item()
{

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
