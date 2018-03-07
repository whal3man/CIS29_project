#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>
using namespace std;

class Player : public Character
{
    public:
        Player(int startingX = 0, int startingY = 0, int startingZ = 9) : Character(startingX, startingY, startingZ) {}

        void runCharacterCreation(const bool DEBUG);

        void displayInventory();

        void equip(int i);
        void unequip();
        Item& getEquippedItem() { return equipped; }

        Item defaultItem = Item("No item equipped", "\"equip\" or \"e\" to equip from inventory");
        Item equipped = defaultItem;

        void attack(Character& e);

        bool wonGame() { return (z < 0); }
};

#endif // PLAYER_H
