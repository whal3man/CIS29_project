#include "../include/COIN.h"

void Cap::change_to_caps(int num)
{
	setValue(num);
	cout << "You have received " << value << " caps now!" << endl;
}

int Cap::operator+(const Cap& a) {
	int total = 0;
	total = this->value + a.value;
	cout << "Total amount is " << total << endl;
	return total;
}

int Cap::operator-(const Cap& a) {
	int diff = 0;
	diff = this->value - a.value;
	if (diff < 0)
	{
		cout << "This is not enough!!" << endl;
		return -1;
	}
	else
	cout << "Total amount is " << diff << endl;
	return diff;
}
