#ifndef MAP_H
#define MAP_H

#include "Tile.h"
#include "Enemy.h"
#include "Item.h"
#include <vector>

class Map
{
    public:
        Map(int rows_ = 10, int cols_ = 10, int floors_ = 10, int startingX = 0, int startingY = 0, int startingZ = 9, double monsterSpawnRate_ = .30, double itemSpawnRate = .30);

        std::vector<std::vector<std::vector<Tile>>> getMap() { return gameMap; }
        Tile& getTile(int x, int y, int z) { return gameMap[x][y][z]; }
        void setTile(int x, int y, int z, Tile t) { gameMap[x][y][z] = t; }
        void setMap(std::vector<std::vector<std::vector<Tile>>> val) { gameMap = val; }

        int numRows() { return rowCount; }
        int numCols() { return colCount; }
        int numFloors() { return floorCount; }

        void print();

        void updatePlayerLoc(int x, int y, int z);
        Tile& playerTile();

        void updateMonsterLocs();

        void displayEnemiesInPlayerTile();
        void displayItemsInPlayerTile();

    protected:

    private:
        std::vector<std::vector<std::vector<Tile>>> gameMap;
        double monsterSpawnRate;
        double itemSpawnRate;
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
