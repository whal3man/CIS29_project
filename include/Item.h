#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item
{
public:
	Item();
	std::string getItemName();
	int getSellValue();
	int getBuyValue();
	void setItemValue(int number);
	void setSellValue(int number);
	void setItemName(std::string ItemName);
private:
	std::string itemName;
	int sellValue;
	int buyValue;
};

#endif // ITEM_H
