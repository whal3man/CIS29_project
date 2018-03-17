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

        void fillInventory();

        bool use(int idx);

        bool wonGame() { return (z < 0); }
        bool lostGame() { return !alive; }

        friend std::ostream& operator<<(ostream& os, const Player& c)
        {
            os << c.name << ", HP = " << c.hp << ", Age = " << c.age << ", Enemies Killed = " << c.enemiesKilled;
            return os;
        }
};

#endif // PLAYER_H
