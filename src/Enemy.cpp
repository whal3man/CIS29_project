#include "../include/Enemy.h"

const std::vector<std::string> Enemy::possibleNames = {"Grognak The Destroyer", "Deathclaw", "Radscorpion", "Raider Clasher"};

Enemy::Enemy() : Character() {}

Enemy::Enemy(int X, int Y, int Z, std::string N, int HP,  std::vector <Item> LOOT, int Age,
             int S, int P, int E, int C, int I, int A, int L,
             int R)
{
    x = X;
    y = Y;
    z = Z;
    name = N;
    hp = HP;
    loot = LOOT;
    age = Age;
    strength = S;
    perception = P;
    endurance = E;
    charisma = C;
    intelligence = I;
    agility = A;
    luck = L;
    aggro_radius = R;
}

// Assume each monster will call this function once after the player moves.
void Enemy::act()
{
}
