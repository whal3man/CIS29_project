#ifndef MAP_H
#define MAP_H

#include "Tile.h"
#include "Enemy.h"
#include <vector>

class Map
{
    public:
        Map(int rows_ = 10, int cols_ = 10, int floors_ = 10, int startingX = 0, int startingY = 0, int startingZ = 9);

        std::vector<std::vector<std::vector<Tile>>> getMap() { return gameMap; }
        Tile getTile(int x, int y, int z) { return gameMap[x][y][z]; }
        void setTile(int x, int y, int z, Tile t) { gameMap[x][y][z] = t; }
        void setMap(std::vector<std::vector<std::vector<Tile>>> val) { gameMap = val; }

        int numRows() { return rowCount; }
        int numCols() { return colCount; }
        int numFloors() { return floorCount; }

        void print();

        void updatePlayerLoc(int x, int y, int z);
        Tile playerTile();

    protected:

    private:
        std::vector<std::vector<std::vector<Tile>>> gameMap;
        std::vector<Enemy> enemies;
        int rowCount;
        int colCount;
        int floorCount;

        int playerStartingX;
        int playerStartingY;
        int playerStartingZ;
        int playerX;
        int playerY;
        int playerZ;
        int currentFloor;
};

#endif // MAP_H
