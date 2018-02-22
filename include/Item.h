#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item
{
public:
	Item();
	~Item();

	// General Item Functions
	std::string getItemName() const
		{ return ItemName; }
	enum getItemType() const
		{ return itemType; }
	int getSellValue() const
		{ return sellValue; }
	int getBuyValue() const
		{ return buyValue; }
	void setBuyValue(int number);
		{ buyValue = number; }
	void setSellValue(int number);
		{ sellValue = number; }
	void setItemName(std::string name);
		{ ItemName = name; }
	void setItemType(enum type);
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
	void setHpRestore(enum type); // Defined in item.h
	void setPakType(enum type)
		{ pakType = type; }

	// Armor Type Functions
	enum getArmorType() const
		{ return armorType; }
	int getDamageResistance() const
		{ return damageResistance; }
	void setDamageResistance(); // Defined in item.h, dependent on armorType
	void setArmorType(enum type)
		{ armorType = type; }

private:
	std::string itemName;
	enum itemType {WEAPON, RECOVERY, LOOT, ARMOR}; 
	int sellValue;
	int buyValue;
	
	// For Weapons
	int ammoCount; 
	int energyCount; 
	int baseDamage; // will likely be subject to other modifiers later on
	
	// For recovery items
	int hpRestore; // For stimpaks, amount of HP restored
	enum pakType {REGULAR, SUPER, ULTRA};  // In order of power

	// For Armor Items
	enum armorType {JUMPSUIT, COMBATARMOR, POWERARMOR};
	int damageResistance; // Scalar value that modifies damage taken from a hit
};

#endif // ITEM_H
