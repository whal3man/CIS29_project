#include "../include/Map.h"
#include "../include/RandNumber.h"
#include <vector>
#include <iostream>
#include <iomanip>

Map::Map(double monsterSpawnRate_, int rows_, int cols_, int floors_, int startingX, int startingY, int startingZ)
{
    monsterSpawnRate = monsterSpawnRate_;

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


                if(x == playerX && y == playerY && z == playerZ) t.playerIn();
                else {
                    if(randDouble(0,1) < monsterSpawnRate)
                    {
                        t.monsterIn();
                    }
                }

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
            else if(currentTile.containsMonster()) std::cout << std::setw(spacesBetweenTiles) << "[M]";
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

void Map::updateMonsterLocs()
{
    for(int y = 0; y < numRows(); y++)
    {
        for(int x = 0; x < numCols(); x++)
        {
            Tile currentTile = getTile(x, y, currentFloor);

            if(currentTile.containsMonster())
            {
                double dir = randDouble(0,1);
                if(dir >= 0 && dir < .25 && !currentTile.checkWall("left"))
                {
                    if(!gameMap[x-1][y][currentFloor].containsPlayer())
                    {
                        gameMap[x-1][y][currentFloor].monsterIn();
                        gameMap[x][y][currentFloor].monsterOut();
                    }
                }
                else if(dir >= .25 && dir < .50 && !currentTile.checkWall("right"))
                {
                    if(!gameMap[x+1][y][currentFloor].containsPlayer())
                    {
                        gameMap[x+1][y][currentFloor].monsterIn();
                        gameMap[x][y][currentFloor].monsterOut();
                    }
                }
                else if(dir >= .50 && dir < .75 && !currentTile.checkWall("up"))
                {
                    if(!gameMap[x][y-1][currentFloor].containsPlayer())
                    {
                        gameMap[x][y-1][currentFloor].monsterIn();
                        gameMap[x][y][currentFloor].monsterOut();
                    }
                }
                else if(dir >= .75 && dir < 1 && !currentTile.checkWall("down"))
                {
                    if(!gameMap[x][y+1][currentFloor].containsPlayer())
                    {
                        gameMap[x][y+1][currentFloor].monsterIn();
                        gameMap[x][y][currentFloor].monsterOut();
                    }
                }
            }
        }
    }
}

Tile Map::playerTile()
{
    return getTile(playerX, playerY, playerZ);
}
