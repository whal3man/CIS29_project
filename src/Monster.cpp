/**************333333333333333****************************
ROAR
Monster class
Inherits from Dialogue class

Exception Handling? Not yet

***********************3333333333333333333333333333333*******/

#include "Monster.h"

Monster::Monster()
{
}


Monster::~Monster()
{
}

/*===$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$=====
hello()
Redefined function from base class
First thing to occur when user meets monster
============$$$$$$$$$$$$$$$$$$$=============*/
void Monster::hello() { cout << "RAAWWWR, I WILL EAT YOU\n"; }

/*=========@@@@@@@@@@@@@@==========
goodbye()
Redefined function from base class
Used when user defeats monster
========@@@@@@@@@@@@@@@===========*/
void Monster::goodbye() { cout << "WAHH I DEAD XD DUN DUN DUN \n"; }
