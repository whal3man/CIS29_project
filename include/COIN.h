/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Cap class
Cap is used as currency 
for various products provided by 
Merchant class for the game 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#ifndef COIN_H
#define COIN_H

#include <iostream>
using namespace std;

class Cap
{
public:
	Cap() { setValue(0); }
	~Cap() {}
	Cap(int num) { setValue(num); }
	
	void setValue(int num) { value = num; }
	int getValue() const { return value; }
	
	void change_to_caps(int caps);
	
	int operator+(const Cap& a);
	int operator-(const Cap& a);

private:
	// Internal value of a cap
	int value;
};

#endif // COIN_H
