/*=========================================
RandoSpeak class - Speech of random characters
encountered in game
(child class of Dialogue)
Subject to change and inclusion of other header files
==========================================*/
#ifndef RAN_H
#define RAN_H

#include "Dialogue.h"

class RandoSpeak :
	public Dialogue
{
public:
	RandoSpeak();
	~RandoSpeak();
	void hello();
	void goodbye();
};

#endif // !RAN_H
