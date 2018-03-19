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
#include <vector>
#include <iomanip>

class Merchant :
	public Dialogue
{
public:
	Inventory makeInventory();
	Merchant() { };
	~Merchant() { };
	void hello();			// Greets user (inherited from Dialogue)
	void goodbye();			// Bought something, so thank message (inherited from Dialogue)
	void changeOfmind();	// Did not buy anything, so this differs from goodbye() obviously
	Character Purchase(Character play, Inventory store_lit);	// Transaction management
	void runThemerch(Character & play);							// Interactive program
	void merchantintro();	// Player knows merchant is there
	friend char yesOrno();		// Data validation (Yes, No, error input)
	friend void itemMenu();	// Display items and their prices
	friend Inventory fiveAddtimes(Item obj, Inventory store);
private:
	Inventory store;	// Initialize store when player encounter
protected:
	//CharacterType MSpeech = merchant;
};

#endif // MERCH_H
