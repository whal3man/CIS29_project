#include "item.h"
// Most of the accessor functions have been defined inline in the specification file, since they're very short.

// I'm assuming we're having health points going from 0 - 100. Can scale as project progresses.
void Item::setHpRestore(enum type) { 
	switch(type) {
		case (REGULAR): hpRestore = 20;
			break;
		case (SUPER): hpRestore = 40;
			break;
		case (ULTRA):  hpRestore = 60;
		// This kind of stimpak didn't exist in the older games, but I figure we might as well have a third type. <3 - Remy
			break;
	}
}

// I arbitrarily chose these scalars; can be redefined as needed
void Item::setDamageResistance() {
	switch(armorType)
		case (JUMPSUIT): damageResistance = 0.1;
			break;
		case (COMBATARMOR): damageResistance = 0.4;
			break;
		case (POWERARMOR): damageResistance = 0.7;
			break;
}
