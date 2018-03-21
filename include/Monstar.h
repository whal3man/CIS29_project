/*=========================================
Monstar class - Speech of Monster for game
(child class of Dialogue)
Borrows from Enemy class to enable monster info use
==========================================*/
#ifndef MONR_H
#define MONR_H

#include "Enemy.h"
#include "Dialogue.h"
 
class Monstar :
	public Dialogue
{
public:
	void get_enemy_name(Enemy & e);
	void hello();
	void goodbye();

	Monstar() {};
	~Monstar() {};
};

#endif // MONR_H
