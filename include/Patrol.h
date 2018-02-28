#include "../include/Enemy.h"
#include <string>
#include <vector>

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

    void act()
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
};
