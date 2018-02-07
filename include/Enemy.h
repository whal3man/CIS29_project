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

Enemy::Enemy() : Character() {}

Enemy::Enemy(int X, int Y, int Z, std::string N, int Age, int HP,
             int S, int P, int E, int C, int I, int A, int L,
             int R, std::vector <Item> LOOT)
{
    x = X;
    y = Y;
    z = Z;
    name = N;
    age = Age;
    hp = HP;
    strength = S;
    perception = P;
    endurance = E;
    charisma = C;
    intelligence = I;
    agility = A;
    luck = L;
    aggro_radius = R;
    loot = LOOT;
}

// Assume each monster will call this function once after the player moves.
void Enemy::act()
{
}

Enemy::~Enemy() {}

// A class for stationary enemies.
class Sentry : public Enemy
{
public:
    Sentry(int X, int Y, int Z, std::string N, int Age, int HP,
           int S, int P, int E, int C, int I, int A, int L,
           int R, std::vector <Item> LOOT)
    : Enemy(X, Y, Z, N, Age, HP, S, P, E, C, I, A, L, R, LOOT) {};

    ~Sentry() {};

    void act();
};

void Sentry::act()
{
//    if (PC in range)
//    {
//        attack();
//    }
//    else
//    {
//        do_nothing();
//    }
}

// A class for enemies that can move back and forth in a straight line.
class Patrol : public Enemy
{
protected:
    int dx, dy, dz, current_steps, max_steps;

public:
    // TODO: find a simpler way to construct PatrollingEnemy object.
    Patrol(int X, int Y, int Z, std::string N, int Age, int HP,
           int S, int P, int E, int C, int I, int A, int L,
           int R, std::vector <Item> LOOT, int DX, int DY, int DZ, int MS)
    : Enemy(X, Y, Z, N, Age, HP, S, P, E, C, I, A, L, R, LOOT)
    {
        dx = DX;
        dy = DY;
        dz = DZ;
        current_steps = 0;
        max_steps = MS;
    };

    ~Patrol();

    void act();
};

void Patrol::act()
{
//    if (PC in range)
//    {
//        move_to_PC();
//    }
//    else
//    {
        // Ideally, the enemy should only move one step at a time.
        x += dx;
        y += dy;
        z += dz;
        if (++current_steps == max_steps)
        {
            // Reverse walking direction.
            dx = -dx;
            dy = -dy;
            dz = -dz;
            current_steps = 0;
        }
//    }
}

// A class for enemies that can hunt the player character.
// It will do a random walk until it finds the player character then it will
// start chasing them. It will do nothing once every few turns to give the
// player a chance to escape.
class Hunter : public Enemy
{
protected:
    int idle_counter, idle_interval;

public:
    Hunter(int X, int Y, int Z, std::string N, int Age, int HP,
           int S, int P, int E, int C, int I, int A, int L,
           int R, std::vector <Item> LOOT, int II)
    : Enemy(X, Y, Z, N, Age, HP, S, P, E, C, I, A, L, R, LOOT)
    {
        idle_counter = 0;
        idle_interval = II;
    }

    ~Hunter();

    void act();
};

void Hunter::act()
{
    if (++idle_counter == idle_interval)
    {
        // do nothing this turn
        idle_counter = 0;
        return;
    }

//    if (PC in range)
//    {
//        move_to_PC();
//    }
//    else
//    {
        // do a random walk
        int r = randInt(0,5);
        if (r == 0) x += 1;
        else if (r == 1) x -= 1;
        else if (r == 2) y += 1;
        else if (r == 3) y -= 1;
        else if (r == 4) z += 1;
        else if (r == 5) z -= 1;
        else { /* do nothing */ }
//    }
}

#endif // ENEMY_H
