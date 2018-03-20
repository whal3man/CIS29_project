
/**************222222222222222222222222222222****************************
SAMURAI JONESY the Merchant
He provides the player with various goods throughout the game
Inherits from Dialogue class, and has a function that use the Item class
Exception Handling? Not yet
***********************222222222222222222222222222222222222222222*******/

#include "Merchant.h"
//#include <iostream>


/*=================&&&&&&&&&&&&&&&&&&=================
makeInventory()
This will create a default inventory for the merchant
when meeting the player
===============&&&&&&&&&&&&&&&&&====================*/
Inventory Merchant::makeInventory()	
{
	void fiveAddtimes(Item A, Inventory Z);

	Inventory store;
	Item item;

	item = Item("Potion", "HEAL");

	fiveAddtimes(item, store);

	item = Item("Revive", "HEAL");

	fiveAddtimes(item, store);

	item = Item("Molotov Bomb", "RANGED WEAPON");

	fiveAddtimes(item, store);

	item = Item("Molotov Bomb", "RANGED WEAPON");

	fiveAddtimes(item, store);

	item = Item("Sword", "MELEE WEAPON");

	fiveAddtimes(item, store);

	return store;
}

/*
fiveAddtimes(Item obj, Inventory & store)
Filling 5 spots of merchant's inventory for each item
For initial populasation of store at beginning of game 
*/
void fiveAddtimes(Item obj, Inventory store)
{
	for (static int i = 0; i < 5; i++) store.add(obj);
}


/*===$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$====
hello()
Redefined function from base class, used in purchase()
First thing to occur when user meets merchant
============$$$$$$$$$$$$$$$$$$$$====================*/
void Merchant::hello() 
{ 
	cout << "Hi there stranger, would you like to buy from Samurai Jonesy?\n\
	You can trust me---\n"; 
}

/*================@@@@@@@@@@@@@@@@@@@@================
goodbye()
Redefined function from base class, used in purchase()
Used when user bought at least one item
====================@@@@@@@@@@@@@@@@@@@@============*/
void Merchant::goodbye() {
	cout << "Thank you for your patronage!\nSamurai Jonesy will see you soon!\n";
}
/*==================###############====================
changeofmind()
Only occur when user bought nothing, used in purchase()
==============###############========================*/
void Merchant::changeOfmind() { 
	cout << "Oh okay, it is good to err on caution, but you must be one tough cookie!\n"; }

/*===============%%%%%%%%%%%%%%================
showvector()
Displays the items along with associated prices
that user bought from merchant (DEBUGGING)
==============%%%%%%%%%%%%%==================*/
void Merchant::showVector()
{
	//	Item temp;
	//
	//	int size = Load.size();
	//
	//	if (size < 1) cout << "\nThere is nothing to show!\n";
	//
	//	else cout << "In this bag, there are " << size << " items currently\n" << "Following is listed below\n";
	//
	//	for (int i = 0; i < size; i++)
	//	{
	//		temp = Load[i];
	//
	//		cout << "Product #" << (i+1) << ": " << "\'" << temp.getItemName() << "\' is worth " << temp.getBuyValue() << " coins"
	//			<< endl;
	//	}
	//	cout << "------------" << endl;
	//	/*for (int i = 0; i < size; i++)
	//	{
	//		temp = Load[i];
	//
	//		cout << "For Product # " << (i + 1) << ": " << temp.getItemName << ", " << temp.getBuyValue << endl;
	//
	//	}*/
}

/*---------------<><><><><><><>----------------
ItemMenu()
Displays the items along with associated prices
and related letter for transaction purposes
---------------<><><><><><><>----------------*/
void itemMenu()
{
	cout << "\nWhat do you want?\n\n";
	cout << setw(25) << "Potion for 15 coins? \t(P)\nRevive for 25 coins? \t(R)" 
	<< "\nMolotov Bomb for 15 coins?  \t(O)\n" << "Sword for 60 coins? \t(S)\n"
		<< "\nPlease type a letter from the list above - ";
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

/*=============++++++++++++++=======================
purchase() - vector <Item> function, make it void function
Transaction management (main fntn of Merchant class)
Comprised of various functions, private and public.
Returns a vector of Items that user 'bought'
===================++++++++++++++++===============*/
void Merchant::Purchase(Character play, Inventory store_lit)
{
	char yesOrno();

	// In transaction or not, confirmation, want to purchase more items
	bool tran = 0, flag = 0, end = 0;	
	char choice;
	static int count = 0;
	
		hello();
	
		// Checks for interaction (Yes for continue, and no will exit interaction)
		while (!flag) //&& (choice != 'y' || choice != 'n'))
		{
			choice = yesOrno();
			/*std::cout << "Type Y or N: ";
			std::cin >> choice;
			choice = tolower(choice);*/
			if (choice == 'y' || choice == 'n')
			{
				flag = 1;
				if (choice == 'y') tran = 1;
				else tran = 0;
			}
			else std::cout << "\nI did not understand. Do you need anything?\n";
	
			//std::cin.ignore(100,'\n');
	
			/*std::cout << "Type Y or N: ";
			std::cin >> choice;
			choice = tolower(choice);
			if (choice == 'y' || choice == 'n') flag = 1;
			else std::cout << "Please try again!\n";*/
		}
	
		// Go further into the interaction
		if (tran)
		{
			Item temp;
			//flag = 0;
			//vector<Item> Load;
	
			while (tran && !end)
			{
				flag = 0;
	
				while (!flag)
				{
					itemMenu();
					cin >> choice, choice = toupper(choice);
					switch (choice)
					{
					case 'P': temp.setItemName("Potion"); flag = 1; break;
					case 'R': temp.setItemName("Revive"); flag = 1; break;
					case 'B': temp.setItemName("Molotov Bomb"); flag = 1; break;
					case 'S': temp.setItemName("Sword"); flag = 1; break;
					default: std::cout << "This is not valid! Please try again...\n"; break;
					}
					cin.ignore(1000, '\n');
				}
				flag = 0;
				// Confirm purchase (Yes for adding to player's shopping cart and continue, 
				// NO will exit interaction)
				while (!flag)
				{
					cout << "\nAre you sure that you want " << temp.getItemName() << " for " << temp.getBuyValue() << "?\n";
					choice = yesOrno();
					/*std::cout << "Type Y or N: ";
					std::cin >> choice;
					choice = tolower(choice);*/
					if (choice == 'y' || choice == 'n')
					{
						flag = 1;
						end = 1;
						if (choice == 'y') 
						{
							if (store_lit.contains(temp))
							{
								play.addToInventory(temp);
								store_lit.remove(temp);
								cout << "This item " << temp.getItemName()
								<< "is in the shopping cart now!\n";
								count++;
							}
							else { cout << "Sorry " << play.getName() << "This item is no longer available!\t\n"; end = 0; }
						}
						else cout << "This is discarded...\n";
					}
					else std::cout << "That made no sense, please answer with valid input!\n";
					//cin.ignore(100, '\n');
				}
	
				while (tran&&end)
				{
					flag = 0;
	
					while (!flag)
					{
						cout << "\nDone shopping?\n";
						choice = yesOrno();
						/*std::cout << "Type Y or N: ";
						std::cin >> choice;
						choice = tolower(choice);*/
						if (choice == 'y' || choice == 'n')
						{
							flag = 1;
							if (choice == 'y') tran = 0;
							else { end = 0; cout << "Wow big trip eh?\n"; }
						}
						else std::cout << "What? I did not understand...\n";
						//cin.ignore(100, '\n');
					}
				}
			}
		}
		// Exit the interaction
		// If player bought something
		if (!tran && count > 0) goodbye();
		// If player did not buy anything	
		else if (!tran && count == 0) changeOfmind();
}

/*
runthemerch()
Overall function for main function
*/
void Merchant::runThemerch(Character play)
{
	store = makeInventory();
	Purchase(play, store);
}
