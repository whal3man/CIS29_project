#include "../include/RandNumber.h"

double randDouble(double a, double b)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    static std::mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<double> distribution (a,b);
    return distribution(generator);
}

int randInt(int a, int b)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    static std::mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> distribution (a,b);
    return distribution(generator);
}
