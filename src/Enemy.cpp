#include "../include/Enemy.h"
#include <string>
#include <vector>

const std::vector<std::string> Enemy::possibleNames = {"Grognak The Destroyer", "Deathclaw", "Radscorpion", "Raider Clasher", "Ghoul", "Rabid Dog", "Yao Guai", "Super Mutant", "Assaultron", "Mobile Turret"};

Enemy::Enemy() : Character() {}

Enemy::Enemy(int X, int Y, int Z, int BX, int BY, std::string N, int HP,  std::vector <Item> LOOT, int Age,
             int S, int P, int E, int C, int I, int A, int L)
{
    x = ax = X;
    y = ay = Y;
    z = Z;
    bx = BX;
    by = BY;
    name = N;
    hp = HP;
    age = Age;
    strength = S;
    perception = P;
    endurance = E;
    charisma = C;
    intelligence = I;
    agility = A;
    luck = L;

    // Add current equipment as possible loot.
    bool equippedWeapon = false;
    bool equippedArmor = false;
    for(int i = 0; i < LOOT.size(); i++)
    {
        inventory.add(LOOT[i]);
        if(!equippedWeapon && LOOT[i].itemType == "MELEE WEAPON" || LOOT[i].itemType == "RANGED WEAPON")
        {
            equip(i);
            equippedWeapon = true;
        }
        if(!equippedArmor && LOOT[i].itemType == "ARMOR")
        {
            equip(i);
            equippedArmor = true;
        }
    }

    // Compute dx and dy (direction of movement)
    dx = dy = 0;
    if (ax != bx) dx = 1;
    else if (ay != by) dy = 1;

    // Make sure ax <= bx and ay <= by
    if (ax > bx)
    {
        int tmp = ax;
        ax = bx;
        bx = tmp;
    }
    if (ay > by)
    {
        int tmp = ay;
        ay = by;
        by = tmp;
    }

    allowMove = true;
    alive = true;
}

std::string Enemy::getDir()
{
    if (dx == 1) return "right";
    else if (dx == -1) return "left";
    else if (dy == 1) return "down";
    else if (dy == -1) return "up";
    else return "none";
}

void Enemy::revDir()
{
    dx *= -1;
    dy *= -1;
}
