/*=========================================
Merchant class - Speech of Merchant for game
(child class of Dialogue)
Borrows from Item class and uses a vector
==========================================*/
#ifndef MERCH_H
#define MERCH_H

#include "Dialogue.h"
#include "Item.h"
#include <vector>
#include <iomanip>

class Merchant :
	public Dialogue
{
public:
	Merchant() { };
	~Merchant() { };
	void hello();	// Greets user
	void goodbye();	// Bought something, so thank message
	void changeofmind();	// Did not buy anything, so this differs from goodbye() obviously
	vector<Item> purchase();	// Transaction management
	void showVector();	// Show what user bought from transaction
	
private:
	char yesOrno();		// Data validation (Yes, No, error input)
	vector<Item> Load;	// Stores Item objects during a transaction
	void itemMenu();	// Display items and their prices
	bool tran, flag, end;	// In transaction or not, confirmation, want to purchase more items
};

#endif // MERCH_H
