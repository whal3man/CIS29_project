// TODO: Documentation.

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Item.h"
#include "RandNumber.h"
#include <vector>
#include <string>

// The Enemy class is an abstract class.
class Enemy : public Character
{
public:
    int aggro_radius;
    std::vector <Item> loot;
    static const std::vector<std::string> possibleNames;

    Enemy();
    ~Enemy() {}

    Enemy(int X, int Y, int Z, std::string N, int HP, std::vector <Item> LOOT, int Age = 20,
          int S = 5, int P = 5, int E = 5, int C = 5, int I = 5, int A = 5, int L = 5, int R = 5);

    void act();

    friend bool operator==(const Enemy& lhs, const Enemy& rhs)
    {
        return (lhs.name == rhs.name && lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.age == rhs.age);
    }

    friend std::ostream& operator<<(std::ostream& os, const Enemy& e)
    {
        os << e.name << " (HP: " << e.hp << ")";
        return os;
    }
};

#endif // ENEMY_H
