#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item 
{
	public:
		Item();
		std::string getItemName();
		int getSellValue();
	private:
		std::string itemName;
		int sellValue;
};

#endif // ITEM_H
