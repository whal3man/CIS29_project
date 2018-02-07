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

    protected:

    private:

};

#endif // PLAYER_H
