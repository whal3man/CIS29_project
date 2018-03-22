// TODO: Documentation.

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Item.h"
#include <vector>
#include <string>
using namespace std;

class Enemy : public Character
{
protected:
    int ax, ay, bx, by, dx, dy;     // Assume either ax == bx, or ay == by

public:
    static const vector<string> possibleNames;
    bool allowMove;

    Enemy();
    ~Enemy() {}

    Enemy(int X, int Y, int Z, int BX, int BY, string N, int HP, vector <Item> LOOT, int CAPS, int Age = 20,
          int S = 5, int P = 5, int E = 5, int C = 5, int I = 5, int A = 5, int L = 5);

    Inventory getLoot()
    {
        return inventory;
    }
    int getAX()
    {
        return ax;
    }
    void setAX (int ax_)
    {
        ax = ax_;
    }
    int getAY()
    {
        return ay;
    }
    void setAY (int ay_)
    {
        ay = ay_;
    }
    int getBX()
    {
        return bx;
    }
    void setBX (int bx_)
    {
        bx = bx_;
    }
    int getBY()
    {
        return by;
    }
    void setBY (int by_)
    {
        by = by_;
    }
    int getDX()
    {
        return dx;
    }
    void setDX (int dx_)
    {
        dx = dx_;
    }
    int getDY()
    {
        return dy;
    }
    void setDY (int dy_)
    {
        dy = dy_;
    }
    string getDir();
    void revDir();

    friend bool operator==(const Enemy& lhs, const Enemy& rhs)
    {
        return (lhs.name == rhs.name && lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.age == rhs.age);
    }

    friend ostream& operator<<(ostream& os, const Enemy& e)
    {
        os << e.name;
        if(e.isAlive())
            cout << "(Alive)";
        else
            cout << "(Dead)";
        os << "\n\tHP: " << e.hp << ", Caps: " << e.inventory.getCaps() << ", Equipped:\n\t\tWeapon: " << e.equippedWeapon << "\n\t\tArmor: " << e.equippedArmor;
        return os;
    }
};

#endif // ENEMY_H
