#include "Item.h"
//#include <iostream>

Item::Item()
{
	/*setItemName("UNDEFINED");
	setSellValue(0);
	setItemValue(0);*/
}

void Item::setItemName(std::string ItemName)
{
	itemName = ItemName;
}

void Item::setItemValue(int number)
{
	buyValue = number;
}

void Item::setSellValue(int number)
{
	sellValue = number;
}

std::string Item::getItemName()
{
	return itemName;
}

int Item::getBuyValue()
{
	return buyValue;
}

int Item::getSellValue()
{
	return sellValue;
}
