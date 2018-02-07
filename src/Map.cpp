#include "Map.h"
#include <vector>
#include <iostream>
#include <iomanip>

Map::Map(int rows_, int cols_, int floors_, int startingX, int startingY, int startingZ)
{
    rowCount = rows_;
    colCount = cols_;
    floorCount = floors_;

    playerX = playerStartingX = startingX;
    playerY = playerStartingY = startingY;
    playerZ = playerStartingZ = startingZ;
    currentFloor = startingZ;

    gameMap.resize(cols_,std::vector<std::vector<Tile>>(rows_,std::vector<Tile>(floors_)));

    for(int z = 0; z < floors_; z++)
    {
        for(int y = 0; y < rows_; y++)
        {
            for(int x = 0; x < cols_; x++)
            {
                Tile t;
                if(x == 0) t.setWall("left");
                if(y == 0) t.setWall("up");
                if(x == cols_-1) t.setWall("right");
                if(y == rows_-1) t.setWall("down");

                setTile(x, y, z, t);
            }
        }
    }
    gameMap[playerX][playerY][playerZ].playerIn();
}

void Map::print()
{
    int spacesBetweenTiles = 5;

    for(int y = 0; y < numRows(); y++)
    {
        for(int x = 0; x < numCols(); x++)
        {
            Tile currentTile = getTile(x, y, currentFloor);

            if(currentTile.containsPlayer()) std::cout << std::setw(spacesBetweenTiles) << "[P]";
            else std::cout << std::setw(spacesBetweenTiles) << "[ ]";
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < numCols()-2; i++)
    {
        std::cout << std::setw(spacesBetweenTiles) << "   ";
    }
    std::cout << " Floor: " << currentFloor+1 << std::endl;
}

void Map::updatePlayerLoc(int x, int y, int z)
{
    gameMap[playerX][playerY][playerZ].playerOut();

    playerX = x;
    playerY = y;
    playerZ = z;
    currentFloor = z;

    gameMap[playerX][playerY][playerZ].playerIn();
}

Tile Map::playerTile()
{
    return getTile(playerX, playerY, playerZ);
}
