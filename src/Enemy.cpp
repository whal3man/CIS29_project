#include "../include/Enemy.h"

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
