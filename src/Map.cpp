#include "Map.h"
#include <vector>
#include <iostream>
#include <iomanip>

Map::Map()
{
    rowCount = 10;
    colCount = 10;
    floorCount = 10;

    playerX = playerStartingX = 0;
    playerY = playerStartingY = 0;
    playerZ = playerStartingZ = 9;
    currentFloor = 9;

    std::vector<std::vector<Tile>> cols;
    std::vector<Tile> row;

    for(int z = 0; z < 10; z++)
    {
        cols.clear();
        for(int y = 0; y < 10; y++)
        {
            row.clear();
            for(int x = 0; x < 10; x++)
            {
                Tile t;
                row.push_back(t);
            }
            cols.push_back(row);
        }
        gameMap.push_back(cols);
    }

    gameMap[playerX][playerY][playerZ].playerIn();
}

Map::Map(int rows_, int cols_, int floors_, int startingX, int startingY, int startingZ)
{
    rowCount = rows_;
    colCount = cols_;
    floorCount = floors_;

    playerX = playerStartingX = startingX;
    playerY = playerStartingY = startingY;
    playerZ = playerStartingZ = startingZ;
    currentFloor = startingZ;

    std::vector<std::vector<Tile>> curCols;
    std::vector<Tile> curRow;

    for(int z = 0; z < floors_; z++)
    {
        curCols.clear();
        for(int y = 0; y < rows_; y++)
        {
            curRow.clear();
            for(int x = 0; x < cols_; x++)
            {
                Tile t;
                curRow.push_back(t);
            }
            curCols.push_back(curRow);
        }
        gameMap.push_back(curCols);
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
            Tile currentTile = gameMap[x][y][currentFloor];

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
