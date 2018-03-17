#include "../include/Enemy.h"
#include <string>
#include <vector>

// A class for stationary enemies.
class Sentry : public Enemy
{
public:
    Sentry(int X, int Y, int Z, std::string N, int Age, int HP,
           int S, int P, int E, int C, int I, int A, int L,
           int R, std::vector <Item> LOOT)
        : Enemy(X, Y, Z, N, Age, HP, S, P, E, C, I, A, L, R, LOOT) {};

    ~Sentry() {};

    void act()
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
};
