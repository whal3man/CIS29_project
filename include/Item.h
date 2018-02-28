#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item
{
public:
	Item();
	~Item();

	enum ItemType {WEAPON, RECOVERY, LOOT, ARMOR};

	enum PakType {REGULAR, SUPER, ULTRA};  // In order of power

	enum ArmorType {JUMPSUIT, COMBATARMOR, POWERARMOR};

	// General Item Functions
	std::string getItemName() const
		{ return itemName; }
	ItemType getItemType() const
		{ return itemType; }
	int getSellValue() const
		{ return sellValue; }
	int getBuyValue() const
		{ return buyValue; }
	void setBuyValue(int number)
		{ buyValue = number; }
	void setSellValue(int number)
		{ sellValue = number; }
	void setItemName(std::string name)
		{ itemName = name; }
	void setItemType(ItemType type)
		{ itemType = type; }

	// Weapon Type Functions
	int getAmmoCount() const
		{ return ammoCount; }
	int getEnergyCount() const
		{ return energyCount; }
	int getBaseDamage() const
		{ return baseDamage; }
	void setAmmoCount(int number)
		{ ammoCount = number; }
	void setEnergyCount(int number)
		{ energyCount = number; }
	void setBaseDamage(int number)
		{ baseDamage = number; }

	// Recovery Type Functions
	int getHpRestore() const
		{ return hpRestore; }
	void setHpRestore(); // Defined in item.h
	void setPakType(PakType type)
		{ pakType = type; }
    PakType getPakType() const
    { return pakType; }

	// Armor Type Functions
	ArmorType getArmorType() const
		{ return armorType; }
	int getDamageResistance() const
		{ return damageResistance; }
	void setDamageResistance(); // Defined in item.h, dependent on armorType
	void setArmorType(ArmorType type)
		{ armorType = type; }

private:
	std::string itemName;
    int itemValue;
    ItemType itemType;
	int sellValue;
	int buyValue;

	// For Weapons
	int ammoCount;
	int energyCount;
	int baseDamage; // will likely be subject to other modifiers later on

	// For recovery items
	int hpRestore; // For stimpaks, amount of HP restored
	PakType pakType;

	// For Armor Items
	int damageResistance; // Scalar value that modifies damage taken from a hit
	ArmorType armorType;
};

#endif // ITEM_H
