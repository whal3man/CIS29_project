/***********1111111111111111111111111111111111111****************

Defines the Dialogue class
Code file of Dialogue.h - hello() and goodbye()
Includes a function that might be adopted { intro(Player play) }

***********11111111111111111111111111111111111111***************/

#include "Dialogue.h"
//#include <iostream>
//#include <string>

/*=========================================================
This function is a possible replacement 
for Player introduction (beginning of runCharacterCreation)
==========================================================*/
void intro(Player play) {

	cout << "Welcome to Escape the Vault.\n";
	cout << "You wake up, cold and confused. You start to remember who you are...\n";

	string input;
	cout << "Who am I?\n";
	getline(cin, input);
	cin.ignore();
	play.setName(input);
	cout << "How old am I?\n";
	cin >> input;
	play.setAge(stoi(input));
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
hello()
Virtual void function for inherited classes 
(Merchant, Monster, Others) to define later on
============$$$$$$$$$$$$$$$$$$$$=============*/
void Dialogue::hello()
{
	//if (self)	{	cout << "Hey what's good?\n";}
	//if (merchant) { cout << "Hi stranger, what would you like to buy?\n"; }
	//if (monster) { cout << "RAAWWWR, I WILL EAT YOU\n"; }
	//if (ordinary) { cout << "I like zucchini pie...but don't trust the dentists!\n"; }

	cout << "All good Pau Gasol" << endl;
}

/*=========@@@@@@@@@@@@@@@@@@@@================
goodbye()
Virtual void function for inherited classes
(Merchant, Monster, Others) to define later on
====================@@@@@@@@@@@@@@@@@@@@=====*/
void Dialogue::goodbye() 
{
	/*if (self)	cout << "See you,wouldn't want to smell ya!\n";
	if (merchant) cout << "Thank you for your patronage!\n";
	if (monster) cout << "WAHH I DEAD XD \n";
	if (ordinary) cout << "Well, going back to the hole...tell your mom that I said hello!\n";*/
	cout << "Sayonara Kiki Galore" << endl;
}
