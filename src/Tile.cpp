#include "../include/Tile.h"
#include "../include/RandNumber.h"
#include <vector>
#include <iostream>
#include <algorithm>

//TODO: populate monster vector
Tile::Tile()
{
    caps = randInt(1, 100);
    elevator = false;
    player = false;
    chest = false;
    setWall("up", false);
    setWall("down", false);
    setWall("left", false);
    setWall("right", false);
}

void Tile::enemyOut(const Enemy& e)
{
     auto idx = find(enemies.begin(), enemies.end(), e);
     if(idx != enemies.end()) enemies.erase(idx);
}

void Tile::removeItem(const Item& i)
{
    auto idx = find(items.begin(), items.end(), i);
    if(idx != items.end()) items.erase(idx);
}

void Tile::removeItem(int i)
{
    items.erase(items.begin() + i);
}
