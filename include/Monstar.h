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
	void enemy_greeting(Enemy & e);
	void hello() override;
	void goodbye() override;

	Monstar() {};
	~Monstar() {};
};

#endif // MONR_H
