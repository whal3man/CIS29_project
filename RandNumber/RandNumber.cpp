#include "RandNumber.h"
#include <ctime>

double randDouble(double a, double b)
{
    static std::mt19937 generator(time(0)); //Standard mersenne_twister_engine seeded with time(0)
    std::uniform_real_distribution<double> distribution (a,b);
    return distribution(generator);
}

int randInt(int a, int b)
{
    static std::mt19937 generator(time(0)); //Standard mersenne_twister_engine seeded with time(0)
    std::uniform_int_distribution<int> distribution (a,b);
    return distribution(generator);
}
