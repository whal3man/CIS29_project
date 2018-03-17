/*=========================================
Base class for speech (parent class of Merchant, Monster, Others) 
==========================================*/
#ifndef DIAG_H
#define DIAG_H

#include "Player.h"
#include <iostream>
#include <string>

// This function will replace the intro lines from runCharacterCreation function of PLAYER class 
void intro(Player play);

class Dialogue {
public:
	virtual void hello() = 0;
	virtual void goodbye() = 0;
//protected:
//	enum CharacterType {self, merchant, monster, ordinary };
};

#endif // DIAG_H
