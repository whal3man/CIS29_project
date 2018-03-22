#ifndef MAP_H
#define MAP_H

#include "Tile.h"
#include "Enemy.h"
#include "Item.h"
#include "Player.h"
#include "RandNumber.h"
#include <vector>

using tile3dVec = std::vector<std::vector<std::vector<Tile>>>;
class Map
{
    public:
        Map(int rows_ = 10, int cols_ = 10, int floors_ = 10, int startingX = 0, int startingY = 0, int startingZ = 9, double monsterSpawnRate_ = .30, double itemSpawnRate = .30);

        tile3dVec getMap() { return gameMap; }
        Tile& getTile(int x, int y, int z) { return gameMap[x][y][z]; }
        void setTile(int x, int y, int z, Tile t) { gameMap[x][y][z] = t; }
        void setMap(std::vector<std::vector<std::vector<Tile>>> val) { gameMap = val; }

        int numRows() { return rowCount; }
        int numCols() { return colCount; }
        int numFloors() { return floorCount; }

        void print();

        void updatePlayerLoc(int x, int y, int z);
        Tile& playerTile();

        bool moveEnemy(Enemy& e);
        void updateEnemyLocs();
        void checkEnemyAttacks(Player& player);
        void checkEnemyDeaths();

        void checkMine(Player& player);
        void checkMinesweeperNumbers();

        void displayEnemiesInPlayerTile();
        void displayItemsInPlayerTile();

    protected:

    private:
        tile3dVec gameMap;
        double monsterSpawnRate;
        double chestSpawnRate;
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
