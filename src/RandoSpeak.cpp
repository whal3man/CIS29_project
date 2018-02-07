/********44444444************
MYAH BYAHHH
RandoSpeak class
Inherits from Dialogue class

Exception Handling? Not yet

*********444444444444*******/

#include "RandoSpeak.h"

RandoSpeak::RandoSpeak()
{
}


RandoSpeak::~RandoSpeak()
{
}

/*===$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$=====
hello()
Redefined function from base class
First thing to occur when user meets random
============$$$$$$$$$$$$$$$$$$$=============*/
void RandoSpeak::hello() { cout << "I like zucchini pie...but don't trust the dentists!\n"; }

/*=========@@@@@@@@@@@@@@=========
goodbye()
Redefined function from base class
Used when user leaves random
========@@@@@@@@@@@@@@@==========*/
void RandoSpeak::goodbye() { cout << "Well, going back to the hole...tell your mom that I said hello!\n"; }
