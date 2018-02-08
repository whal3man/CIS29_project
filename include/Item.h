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
	std::string getItemName();
	enum getItemType();
	int getSellValue();
	int getBuyValue();
	void setItemValue(int number);
	void setSellValue(int number);
	void setItemName(std::string ItemName);
	void setItemType(enum ItemName);

	// Weapon Type Functions
	int getAmmoCount();
	int getEnergyCount();
	int getBaseDamage();
	void setAmmoCount(int number);
	void setEnergyCount(int number);
	void setBaseDamage(int number);
	
	// Recovery Type Functions
	int getHpRestore();
	void setHpRestore(enum pakType); // Different pak Types give different HP
	void setPakType(enum pakType);

	// Armor Type Functions
	enum getArmorType();
	int getDamageResistance(enum armorType);
	void setArmorType(enum armorType);

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
	int damageResistance; // will reduce damage taken from a hit
};

#endif // ITEM_H
