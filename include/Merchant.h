/*=========================================
Merchant class - Speech of Merchant for game
Borrows from Item class and uses a vector
==========================================*/
#ifndef MERCH_H
#define MERCH_H
#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include <vector>
#include <iomanip>

class Merchant
{
public:
	Inventory makeInventory();
	Merchant() { };
	~Merchant() { };
	void hello();			// Greets user (inherited from Dialogue)
	void goodbye();			// Bought something, so thank message (inherited from Dialogue)
	void changeOfMind();	// Did not buy anything, so this differs from goodbye() obviously
	Character purchase(Character play, Inventory store_lit);	// Transaction management
	void runTheMerch(Character & play);							// Interactive program
	void merchantIntro();	// Player knows merchant is there
	friend char yesOrNo();		// Data validation (Yes, No, error input)
    void itemMenu();	// Display items and their prices
	friend Inventory fiveAddTimes(Item obj, Inventory store);
private:
	Inventory store;	// Initialize store when player encounter
protected:
};

#endif // MERCH_H
