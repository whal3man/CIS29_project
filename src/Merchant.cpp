
/**************222222222222222222222222222222****************************
SAMURAI JONESY the Merchant
He provides the player with various goods throughout the game
Inherits from Dialogue class, and has a function that use the Item class
***********************222222222222222222222222222222222222222222*******/

#include "../include/Merchant.h"
#include "../include/Commands.h"

/*&&&&&&&&&&&&&&&&&&&==================================
fiveAddtimes(Item obj, Inventory & store)
Filling 5 spots of merchant's inventory for each item
For initial populasation of store at beginning of game
&&&&&&&&&&&&&&&&&====================================*/
Inventory addTimes(const Item obj, Inventory& store, int numItems)
{
	for (int i = 0; i < numItems; i++) {
	store.add(obj);
	}

	return store;

}

/*=================&&&&&&&&&&&&&&&&&&=================
makeInventory()
This will create a default inventory for the merchant
when meeting the player
===============&&&&&&&&&&&&&&&&&====================*/
Inventory Merchant::makeInventory()
{
	Inventory fiveAddtimes(Item A, Inventory Z);

	Inventory store;
	Item item;

	item = Item("Stimpak");

	store = addTimes(item, store, 3);

	item = Item("Apple");

	store =  addTimes(item, store, 3);

	item = Item("DeathClaw Gauntlet");

	store = addTimes(item, store, 3);

	item = Item("Longsword");

	store = addTimes(item, store, 3);

	return store;
}

/*===$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$====
hello()
Redefined function from base class, used in purchase()
First thing to occur when user meets merchant
============$$$$$$$$$$$$$$$$$$$$====================*/
void Merchant::hello()
{
	cout << "\nHi there stranger, would you like to buy from Samurai Jonesy?\n\n";
}

/*================@@@@@@@@@@@@@@@@@@@@================
goodbye()
Redefined function from base class, used in purchase()
Used when user bought at least one item
====================@@@@@@@@@@@@@@@@@@@@============*/
void Merchant::goodbye() {
	cout << "Thank you for your patronage!\nSamurai Jonesy will see you soon!\n";
}
/*=====+++++++++++++++==========================
To indicate that player encountered the merchant
++++++++++++++=================================*/
void Merchant::merchantIntro() {
	cout << "Hello there, I am the merchant of this lovely game!\n\t" <<
		"You trying to get out of this crazy place?!?\n\n" <<
		"\tWhy not buy from me to get ready for that last boss perhaps?\n\t" <<
		"Enter \"b\" to get something from me\n";
}

/*==================###############====================
changeofmind()
Only occur when user bought nothing, used in purchase()
==============###############========================*/
void Merchant::changeOfMind() {
	cout << "Oh okay, it is good to err on caution, but you must be one tough cookie!\n"; }

/*---------------<><><><><><><>----------------
ItemMenu()
Displays the items along with associated prices
and related letter for transaction purposes
---------------<><><><><><><>----------------*/
void Merchant::itemMenu()
{
	cout << "\nWhat do you want?\n\n";
	for(auto item : store.items)
    {
        cout << setw(25) << item.itemName << " for " << item.itemValue  << " coins?\t\t" << item.itemName[0] << endl;
    }
	cout << "\nPlease type a letter from the list above. ";
}

/*-----------------???????????---------------
yesOrno() - CHAR function
Prompts user for answer, can accept strings
since it only looks at first character anyway
Returns the first character of user input
-----------------???????????---------------*/
char yesOrNo() {
	char letter;
	std::cout << "Type Y or N: ";
	std::cin >> letter;
	letter = tolower(letter);
	cin.ignore(1000, '\n');
	return letter;
}

/*=============++++++++++++++=======================
purchase() - vector <Item> function, make it void function
Transaction management (main fntn of Merchant class)
Comprised of various functions, private and public.
Returns a vector of Items that user 'bought'
===================++++++++++++++++===============*/
Character Merchant::purchase(Character play)
{
	char yesOrNo();

	// In transaction or not, confirmation, want to purchase more items
	bool tran = 0, flag = 0, end = 0;
	char choice;
	static int count = 0;

	system(clsCommand.c_str());

	hello();
		// Checks for interaction (Yes for continue, and no will exit interaction)
		while (!flag) //&& (choice != 'y' || choice != 'n'))
		{
			choice = yesOrNo();

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
					case 'S': temp = Item("Stimpak"); flag = 1; break;
					case 'A': temp = Item("Apple"); flag = 1; break;
					case 'D': temp = Item("DeathClaw Gauntlet"); flag = 1; break;
					case 'L': temp = Item("Longsword"); flag = 1; break;
					default: std::cout << "This is not valid! Please try again...\n"; break;
					}
					cin.ignore(1000, '\n');
				}
				flag = 0;
				// Confirm purchase (Yes for adding to player's shopping cart and continue,
				// NO will exit interaction)
				while (!flag)
				{
					cout << "\nAre you sure that you want " << temp.getItemName() << " for " << temp.getItemValue() << "?\n";
					choice = yesOrNo();

					if (choice == 'y' || choice == 'n')
					{
						flag = 1;
						end = 1;
						if (choice == 'y')
						{
							if (store.contains(temp))
							{
							    if(play.inventory.getCaps() >= temp.itemValue)
								{
								    play.inventory.subCaps(temp.itemValue);
								    play.addToInventory(temp);
                                    store.remove(temp);
                                    cout << "This item " << temp.getItemName() << " is in the shopping cart now!\n";
                                    count++;
								}
								else cout << "I'm sorry, looks like you don't have enough caps for that.\n";
							}
							else cout << "Sorry " << play.getName() << "This item is no longer available!\t\n"; end = 0;
						}
						else cout << "This is discarded...\n";
					}
					else std::cout << "That made no sense, please answer with valid input!\n";
					system(pauseCommand.c_str());
				}


					flag = 0;

					while (!flag)
					{
						cout << "\nDone shopping?\n";
						choice = yesOrNo();

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
		else if (!tran && count == 0) changeOfMind();
		return play;
}

/*
runthemerch()
Overall function for main function
*/
void Merchant::runTheMerch(Character & play)
{
	play = purchase(play);
}
