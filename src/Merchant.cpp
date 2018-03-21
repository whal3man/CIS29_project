
/**************222222222222222222222222222222****************************
SAMURAI JONES the Merchant
He provides the player with various goods throughout the game
Inherits from Dialogue class, and has function that uses various classes
Exception Handling? Not yet
***********************222222222222222222222222222222222222222222*******/

#include "../include/Merchant.h"
#include "../include/Commands.h"

/*
A constant vector of Items that various Merchant functions will use
*/
const vector<Item> Merchant::possibleItems = 
{ 
	Item("Potion", "RECOVERY"), Item("Stimpak", "RECOVERY"), Item("Apple","RECOVERY"),
	Item("Hunting Rifle", "RANGED WEAPON"), Item("Molotov Bomb", "RANGED WEAPON"), 
	Item("Large Club", "MELEE WEAPON"), Item("Light Armor", "ARMOR"), Item("Heavy Armor", "ARMOR"),
	Item("Steel", "MATERIAL"), Item("Leather", "MATERIAL"),	Item("GasContainer", "MATERIAL"), 
	Item("Claw", "MATERIAL"), Item("Ruby", "MATERIAL"), Item("Wizard Gem", "MATERIAL"), Item("Mini Nuke", "RANGED WEAPON")
}; 

/*=================&&&&&&&&&&&&&&&&&&=================
makeInventory()
This will create a default inventory for the merchant
when meeting the player.
===============&&&&&&&&&&&&&&&&&====================*/
Inventory Merchant::makeInventory()	
{
	Inventory addTimes(Item A, Inventory Z, int number);
	
	Inventory store;
	Item item;
	
	store.caps = 1200;
	
	for (unsigned int i = 0; i < possibleItems.size(); i++)
	{
		item = possibleItems[i];
		store = addTimes(item, store, 3);
	}
	return store;
}

/*&&&&&&&&&&&&&&&&&&&==================================
fiveAddtimes(Item obj, Inventory & store)
Filling 5 spots of merchant's inventory for each item
For initial populasation of store at beginning of game 
&&&&&&&&&&&&&&&&&====================================*/
Inventory addTimes(Item obj, Inventory store, int numItems)
{
	for (int i = 0; i < numItems; i++) store.add(obj);
	
	return store;

}

/*===$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$====
hello()
Redefined function from base class, used in purchase()
First thing to occur when user meets merchant
============$$$$$$$$$$$$$$$$$$$$====================*/
void Merchant::hello() 
{ 
	cout << "\nHi there stranger, would you like to buy from Samurai Jones?\n\n"; 
}

/*================@@@@@@@@@@@@@@@@@@@@================
goodbye()
Redefined function from base class, used in purchase()
Used when user bought at least one item
====================@@@@@@@@@@@@@@@@@@@@============*/
void Merchant::goodbye() {
	cout << "Thank you for your patronage!\nSamurai Jones will see you soon! Believe it!\n";
}
/*=====+++++++++++++++==========================
To indicate that player encountered the merchant
++++++++++++++=================================*/
void Merchant::merchantIntro() {
	cout << "Hello there, I am the merchant of this lovely game!\n\t" <<
		"You trying to get out of this crazy place?!?\n\n" <<
		"\tWhy not buy from me to get ready for that last boss perhaps?\n\t" << 
		"Enter \"b\" to talk and shop\n";
}

/*==================###############====================
changeofmind()
Only occur when user bought nothing, used in purchase()
==============###############========================*/
void changeOfmind() { 
	cout << "Oh okay, it is good to err on caution, but you must be one tough cookie!\n"; }

/*---------------<><><><><><><>----------------
ItemMenu()
Displays the items along with associated prices
and related letter for transaction purposes
---------------<><><><><><><>----------------*/
void Merchant::itemMenu()
{
	Item radar;
	char rep;
	cout << "\nWhat do you want?\n\n";
	cout << "Item\t\tItem Type\tCost (caps)  Letter\n";

	int size = possibleItems.size();
	for (int i = 0; i < size; i++)
	{
		radar = possibleItems[i];
		rep = radar.getItemName()[0];
		if (radar.getItemName() == "Stimpak") rep = 'T';
		if (radar.getItemName() == "Hunting Rifle") rep = 'U';
		if (radar.getItemName() == "Large Club") rep = '*';
		if (radar.getItemName() == "Light Armor") rep = '%';
		if (radar.getItemName() == "Mini Nuke") rep = 'Z';

		cout << setw(14) << left << radar.getItemName() << "("  << radar.getItemType() << setw(20-(radar.getItemType().length()))<< ")" 
			<< setw(12) << radar.getItemValue()  <<"(" << rep << setw(2) << ")\n";
	}
		cout << "\nPlease type a letter from the list above (\'?\' for info on items) - ";
}

/*-----------------???????????---------------
yesOrno() - CHAR function
Prompts user for answer, can accept strings
since it only looks at first character anyway
Returns the first character of user input
-----------------???????????---------------*/
char yesOrno() {
	char letter;
	std::cout << "Type Y or N: ";
	std::cin >> letter;
	letter = tolower(letter);
	cin.ignore(1000, '\n');
	return letter;
}


void Merchant::help_item(Item item_)
{
	cout << item_.getItemName();
	if (item_.getItemName() == "Potion")	cout << "- This item will restore 20 HP\n";
	if (item_.getItemName() == "Stimpak")	cout << "- This item will restore 50 HP\n";
	if (item_.getItemName() == "Apple")	cout << "- This item will restore 15 HP\n";
	if (item_.getItemName() == "Hunting Rifle")	cout  << "- This ranged weapon will inflict 30 HP to enemies, and have ammo count of 20\n";
	if (item_.getItemName() == "Molotov Bomb")	cout <<  "- This ranged weapon will inflict 25 HP to enemies, and have ammo count of 10\n";
	if (item_.getItemName() == "Large Club")	cout <<  "- A melee weapon that will inflict 20 HP to enemies\n";
	if (item_.getItemName() == "Light Armor")	cout <<  "- This armor will somehow protect you from dying (better than no armor)\n";
	if (item_.getItemName() == "Heavy Armor")	cout <<  "- This is high-class armor that is doubly effective!\n";
	if (item_.getItemName() == "Steel")	cout << "- Shiny material that can be used for crafting\n";
	if (item_.getItemName() == "Leather")	cout << "- Soft-touch material that can be used for crafting\n";
	if (item_.getItemName() == "GasContainer")	cout << "- Storage of fuel that can be used for crafting\n";
	if (item_.getItemName() == "Claw")	cout << "- Scratch me not, for you can use it for crafting\n";
	if (item_.getItemName() == "Ruby")	cout << "- Ooo so shiny!?! Use in crafting only\n";
	if (item_.getItemName() == "Wizard Gem")	cout << "- Are you a wizard? Crafting only\n";
	if (item_.getItemName() == "Mini Nuke")	cout << "- Now go blow it up! Super weapon\n";

}

/*=============++++++++++++++=======================
purchase() - vector <Item> function, make it void function
Transaction management (main fntn of Merchant class)
Comprised of various functions, private and public.
Returns a vector of Items that user 'bought'
===================++++++++++++++++===============*/
Player Merchant::Purchase(Player play)
{
	char yesOrno();

	// In transaction or not, confirmation, want to purchase more items
	bool tran = 0, flag = 0, end = 0;	
	char choice;
	static int count = 0;

	system(clsCommand.c_str());
	
	hello();
		// Checks for interaction (Yes for continue, and no will exit interaction)
		while (!flag) //&& (choice != 'y' || choice != 'n'))
		{
			choice = yesOrno();

			if (choice == 'y' || choice == 'n')
			{
				flag = 1;
				if (choice == 'y') tran = 1;
				else tran = 0;
			}
			else std::cout << "\nI did not understand. Do you need anything?\n";
		}
	
		// Go further into the interaction
		if (tran)
		{
			Item temp;

			while (tran && !end)
			{
				flag = 0;
	
				while (!flag)
				{
					itemMenu();
					cin >> choice, choice = toupper(choice);
					switch (choice)
					{
					case 'P': temp = Item("Potion"); flag = 1; break;
					case 'T': temp = Item("Stimpak"); flag = 1; break;
					case 'M': temp = Item("Molotov Bomb"); flag = 1; break;
					case 'S': temp = Item("Steel"); flag = 1; break;
					case 'A': temp = Item("Apple"); flag = 1; break;
					case 'U': temp = Item("Hunting Rifle"); flag = 1; break;
					case '*': temp = Item("Large Club"); flag = 1; break;
					case '%': temp = Item("Light Armor"); flag = 1; break;
					case 'H': temp = Item("Heavy Armor"); flag = 1; break;
					case 'L': temp = Item("Leather"); flag = 1; break;
					case 'G': temp = Item("GasContainer"); flag = 1; break;
					case 'C': temp = Item("Claw"); flag = 1; break;
					case 'R': temp = Item("Ruby"); flag = 1; break;
					case 'W': temp = Item("Wizard Gem"); flag = 1; break;
					case 'Z': temp = Item("Mini Nuke"); flag = 1; break;
					case '?': system(clsCommand.c_str()); for (unsigned int i = 0; i < possibleItems.size(); i++) { help_item(possibleItems[i]); cout << endl; } system(pauseCommand.c_str()); break;
					default: cout << "This is not valid! Please try again...\n"; break;
					}
					cin.ignore(1000, '\n');
					system(clsCommand.c_str());
				}
				flag = 0;
				// Confirm purchase (Yes for adding to player's shopping cart and continue, 
				// NO will exit interaction)
				while (!flag)
				{
					cout << "\nAre you sure that you want " << temp.getItemName() << " for " << temp.getItemValue() << "?\n";
					choice = yesOrno();

					if (choice == 'y' || choice == 'n')
					{
						flag = 1;
						end = 1;
						if (choice == 'y') 
						{
							if (store.contains(temp))
							{
								if (play.inventory.getCaps() >= temp.itemValue)
								{
									play.inventory.subCaps(temp.itemValue);
									play.addToInventory(temp);
									store.remove(temp);
									cout << "This item " << temp.getItemName() << " is in the shopping cart now!\n";
									count++;
								}
								else cout << "I'm sorry, looks like you don't have enough caps for that.\n";
							}
							else { cout << "Sorry " << play.getName() << "This item is no longer available!\t\n"; end = 0; }
						}
						else cout << "This is discarded...\n";
					}
					else cout << "That made no sense, please answer with valid input!\n";
					system(pauseCommand.c_str());
				}
	
					flag = 0;
	
					while (!flag)
					{
						cout << "\nDone shopping?\n";
						choice = yesOrno();

						if (choice == 'y' || choice == 'n')
						{
							flag = 1;
							if (choice == 'y') tran = 0;
							else { end = 0; cout << "Wow big trip eh?\n"; }
						}
						else std::cout << "What? I did not understand...\n";
						system(clsCommand.c_str());
					}
				}
			}
		
		// Exit the interaction
		// If player bought something
		if (!tran && count > 0) goodbye();
		// If player did not buy anything	
		else if (!tran && count == 0) changeOfmind();
		return play;
}

/*
runthemerch()
Overall function for main function
*/
void Merchant::runTheMerch(Player & play)
{
	play = Purchase(play);
}
