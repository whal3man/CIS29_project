#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Item
{
public:
    static const vector<Item> possibleItems;
    static const vector<Item> possibleWeapons;

    Item() {}
    Item(string itemName_, string itemType_ = "MISC", int itemValue = 10);
    ~Item();

    // General Item Functions
    string getItemName() const
    {
        return itemName;
    }
    string getItemType() const
    {
        return itemType;
    }
    int getItemValue() const
    {
        return itemValue;
    }
    void setItemName(string name)
    {
        itemName = name;
    }
    void setItemType(string type)
    {
        itemType = type;
    }

    // Weapon Type Functions
    int getAmmoCount() const
    {
        return ammoCount;
    }
    int getBaseDamage() const
    {
        return baseDamage;
    }
    void setAmmoCount(int number)
    {
        ammoCount = number;
    }
    void setDamage(int number)
    {
        damage = number;
    }

    // Recovery Type Functions
    int getHpRestore() const
    {
        return hpRestore;
    }

    // Armor Type Functions
    int getDamageResistance() const
    {
        return damageResistance;
    }

    friend bool operator==(const Item& lhs, const Item& rhs)
    {
        return (lhs.itemName == rhs.itemName);
    }

    friend bool operator!=(const Item& lhs, const Item& rhs)
    {
        return !(lhs == rhs);
    }

    friend ostream& operator<<(ostream& os, const Item& i)
    {
        os << i.itemName << " (" << i.itemType;
        if(i.itemType == "RECOVERY")
            os << ", HP Gain = " << i.hpRestore;
        else if(i.itemType == "ARMOR")
            os << ", Damage Resistance = " << i.damageResistance;
        else if(i.itemType == "MELEE WEAPON")
            os << ", Damage = " << i.damage;
        else if(i.itemType == "RANGED WEAPON")
            os << ", Damage = " << i.damage << ", Ammo Count = " << i.ammoCount;
        os << ")";
        return os;
    }

    string itemName;
    int itemValue;
    string itemType;

    // For Weapons
    int ammoCount;
    int baseDamage; // will likely be subject to other modifiers later on
    int damage;

    // For recovery items
    int hpRestore; // For stimpaks, amount of HP restored

    // For Armor Items
    int damageResistance; // Scalar value that modifies damage taken from a hit
};

#endif // ITEM_H
