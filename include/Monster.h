/*=========================================
Monster class - Speech of Monster when 
encountered in game 
(child class of Dialogue)
Subject to change and inclusion of other header files
==========================================*/
#ifndef MON_H
#define MON_H

#include "Dialogue.h"
//#include <iostream>

class Monster :
	public Dialogue
{
public:
	Monster();
	~Monster();
	void hello();
	void goodbye();
};

#endif // !MON_H
