#include "../include/Monstar.h"

void Monstar::hello() {
	cout << "\n\tRAWR I will eat you!?!\n";
}

void Monstar::goodbye() {
	cout << "\nDA\tDA\tDA\tDA\tDA\tDATARUM!\t(The monster has fallen)\nVICTORY!!\n";
}

void Monstar::enemy_greeting(Enemy & e){

	string name;
	name = e.getName();
	
	if (name == "Grognak The Destroyer")
		cout << "\n\tGrogogo I am going to destroy you!\n";
	else if (name == "Deathclaw")
		cout << "\n\tAin't no ravenclaw. This ain't Harry Potter no mo\n";
	else if (name == "Radscorpion")
		cout << "\n\tWesley Snipes ain't got nothing on me sucka!\n";
	else if (name == "Raider Clasher")
		cout << "\n\tI am part of Raider Nation!\n";
	else if (name == "Ghoul")
		cout << "\n\tI am part of the ghoulish Army that will stop you!\n";
	else if (name == "Rabid Dog")
		cout << "\n\tGrr I will bite your face off!\n";	
	else if (name == "Super Mutant")
		cout << "\n\tX-MEN once hit me up, but Wolverine was not down...\n";	
	else if (name == "Yao Guai")
		cout << "\n\tThis ain't no ying and yang in this game!\n";	
	else if (name == "Assaultron")
		cout << "\n\tTransformers, robots in disguise...oh wait wrong series\n";
	else if (name == "Mobile Turret")
		cout << "\n\tRuttatutut!!\n";
}
