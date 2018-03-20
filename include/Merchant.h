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
	void hello();	// Greets user
	void goodbye();	// Bought something, so thank message
	void changeOfmind();	// Did not buy anything, so this differs from goodbye() obviously
	void Purchase(Character play, Inventory store_lit);	// Transaction management
	void runThemerch(Character play);
	void showVector();	// Show what user bought from transaction
	friend char yesOrno();		// Data validation (Yes, No, error input)
	friend void itemMenu();	// Display items and their prices
	friend void fiveAddtimes(Item obj, Inventory store);
private:
	Inventory store;
	//vector<Item> Load;	// Stores Item objects during a transaction
};

#endif // MERCH_H
