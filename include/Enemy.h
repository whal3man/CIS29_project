// TODO: Documentation.

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Item.h"
#include "RandNumber.h"
#include <vector>

// The Enemy class is an abstract class.
class Enemy : public Character
{
protected:
    int aggro_radius;
    std::vector <Item> loot;

public:
    Enemy();

    Enemy(int X, int Y, int Z, std::string N, int Age, int HP,
          int S, int P, int E, int C, int I, int A, int L,
          int R, std::vector <Item> LOOT);

    virtual ~Enemy();

    virtual void act() = 0;
};

#endif // ENEMY_H
