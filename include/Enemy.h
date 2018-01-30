// TODO: Documentation.

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <functional>

class Enemy : public Character
{
private:
    // Use std::function to make it easy to create a custom behavior
    // function for any individual monster.
    std::function<void ()> behavior_fn;

    // Should have a list of items that can be gained from this enemy.

protected:

public:
    Enemy();

    Enemy(int X, int Y, int Z, std::string N, int Age, int HP,
          int S, int P, int E, int C, int I, int A, int L,
          std::function<void ()> behavior = STATIONARY);

    // Declare some simple behavior functions.
    static const std::function<void ()> STATIONARY;
    static const std::function<void ()> SIMPLE_PATROL;
    static const std::function<void ()> RANDOM;

    void act();

    ~Enemy();
};

Enemy::Enemy() : Character() {}

Enemy::Enemy(int X, int Y, int Z, std::string N, int Age, int HP,
             int S, int P, int E, int C, int I, int A, int L,
             std::function<void ()> behavior)
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
    behavior_fn = behavior;
}

// TODO: Complete these three default behavior functions.
const std::function<void ()> Enemy::STATIONARY = []() {};
const std::function<void ()> Enemy::SIMPLE_PATROL = []() {};
const std::function<void ()> Enemy::RANDOM = []() {};

// Assume each monster will call this function once after the player moves.
void Enemy::act()
{
    // Call the behavior function.
    behavior_fn();
}

Enemy::~Enemy() {}

#endif // ENEMY_H
