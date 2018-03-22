#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>
using namespace std;

class Player : public Character
{
public:
    Player() = default;
    Player(int startingX = 0, int startingY = 0, int startingZ = 9) : Character(startingX, startingY, startingZ)
    {
        shouldOutput = true;
    }

    void runCharacterCreation(const bool DEBUG) override;

    void displayInventory();

    void fillInventory();

    bool use(int idx);

    bool wonGame()
    {
        return (z < 0);
    }
    bool lostGame()
    {
        return !alive;
    }

    friend ostream& operator<<(ostream& os, const Player& c)
    {
        os << c.name << ", HP = " << c.hp << ", Caps: " << c.inventory.getCaps() << ", Age = " << c.age << ", Enemies Killed = " << c.enemiesKilled;
        return os;
    }
};

#endif // PLAYER_H
