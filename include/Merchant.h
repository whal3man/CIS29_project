/*=========================================
Merchant class - Speech of Merchant for game
(child class of Dialogue)
Borrows from Item class and uses a vector
==========================================*/
#ifndef MERCH_H
#define MERCH_H
#include "Inventory.h"
#include "Dialogue.h"
#include "Item.h"
#include <iomanip>

class Merchant :
	public Dialogue
{
public:
	static const vector<Item> possibleItems;
	Inventory makeInventory();
	Merchant() { store = makeInventory(); };
	~Merchant() { };
	void hello() override;			// Greets user (inherited from Dialogue)
	void goodbye() override;			// Bought something, so thank message (inherited from Dialogue)
	void itemMenu();	// Display items and their prices
	void merchantIntro();	// Player knows merchant is there
	void help_item(Item item_);	// Display item info
	Player Purchase(Player play);	// Transaction management
	void runTheMerch(Player & play);							// Interactive program
	
	
	friend char yesOrno();		// Data validation (Yes, No, error input)
	friend Inventory addTimes(Item obj, Inventory store, int numItems);
	friend void changeOfmind();	// Did not buy anything, so this differs from goodbye() obviously

private:
	Inventory store;	// Initialize store when player encounter
protected:
	//CharacterType MSpeech = merchant;
};

#endif // MERCH_H
