#include "../include/Enemy.h"
#include <string>
#include <vector>

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

    void act()
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
        if (r == 0)
            x += 1;
        else if (r == 1)
            x -= 1;
        else if (r == 2)
            y += 1;
        else if (r == 3)
            y -= 1;
        else if (r == 4)
            z += 1;
        else if (r == 5)
            z -= 1;
        else { /* do nothing */ }
//    }
    }
};
