#include "Monstar.h"

void Monstar::hello() {
	cout << "\n\tRAWR I will eat you!?!\n";
}

void Monstar::goodbye() {
	cout << "DA\tDA\tDA\tDA\tDATARUM!\t(I am dead)\nVICTORY!!";
}

void Monstar::get_enemy_name(Enemy & e){

	string name;
	name = e.getName();
	
	if (name == "Grognak The Destroyer")
		cout << "\tGrogogo I am going to destroy you!\n";
	else if (name == "Deathclaw")
		cout << "\tAin't no ravenclaw. This ain't Harry Potter no mo\n";
	else if (name == "Radscorpion")
		cout << "\tWesley Snipes ain't got nothing on me sucka!\n";
	else if (name == "Raider Clasher")
		cout << "\tI am part of Raider Nation!\n";
}

