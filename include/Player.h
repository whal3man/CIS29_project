#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>
using namespace std;

class Player : public Character
{
    public:
        Player() : Character() {}

        void runCharacterCreation(const bool DEBUG);

    protected:

    private:

};

#endif // PLAYER_H
