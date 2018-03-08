#include "../include/Map.h"
#include "../include/RandNumber.h"
#include <vector>
#include <iostream>
#include <iomanip>


Map::Map(int rows_, int cols_, int floors_, int startingX, int startingY, int startingZ, double monsterSpawnRate_, double itemSpawnRate_)
{
    // Settings not important enough to include in constructor
    int maxMonsterHP = 100;
    int minMonsterHP = 80;

    monsterSpawnRate = monsterSpawnRate_;
    itemSpawnRate = itemSpawnRate_;

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
        // Elevator choice
        int elevatorX = randInt(0, cols_-1);
        int elevatorY = randInt(0, rows_-1);

        for(int y = 0; y < rows_; y++)
        {
            for(int x = 0; x < cols_; x++)
            {
                Tile t;
                if(x == 0)
                    t.setWall("left");
                if(y == 0)
                    t.setWall("up");
                if(x == cols_-1)
                    t.setWall("right");
                if(y == rows_-1)
                    t.setWall("down");


                if(x == playerX && y == playerY && z == playerZ)
                    t.playerIn();
                else if(x == elevatorX && y == elevatorY) t.makeElevator();
                else
                {
                    // Monster Generation
                    // Some bits randomly created,
                    if(randDouble(0,1) < monsterSpawnRate)
                    {
                        vector<Item> loot; // Need to fill this
                        int s = Enemy::possibleNames.size();
                        int randIndex = randInt(0, s-1);
                        std::string newEnemyName = Enemy::possibleNames[randIndex];
                        int randHP = randInt(minMonsterHP, maxMonsterHP+1);
                        Enemy newEnemy(x, y, z, newEnemyName, randHP, loot);
                        t.enemyIn(newEnemy);
                    }

                    // Item Generation
                    // Every healthkit/rifle/whatever is the exact same
                    if(randDouble(0,1) < itemSpawnRate)
                    {
                        int s = Item::possibleItems.size();
                        int randIndex = randInt(0, s-1);
                        Item newItem = Item::possibleItems[randIndex];
                        t.addItem(newItem);
                    }
                }


                setTile(x, y, z, t);
            }
        }
    }
//    gameMap[playerX][playerY][playerZ].playerIn();
}

void Map::print()
{
    int spacesBetweenTiles = 5;

    for(int y = 0; y < numRows(); y++)
    {
        for(int x = 0; x < numCols(); x++)
        {
            Tile currentTile = getTile(x, y, currentFloor);

            if(currentTile.containsPlayer())
                std::cout << std::setw(spacesBetweenTiles) << "[P]";
            else if(currentTile.containsElevator())
                std::cout << std::setw(spacesBetweenTiles) << "[E]";
            else if(currentTile.containsEnemy())
                std::cout << std::setw(spacesBetweenTiles) << "[M]";
            else if(currentTile.containsItem())
                std::cout << std::setw(spacesBetweenTiles) << "[I]";
            else
                std::cout << std::setw(spacesBetweenTiles) << "[ ]";
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

            if(currentTile.containsEnemy())
            {
                int numEnemies = currentTile.getNumEnemies();
                for(int i = numEnemies-1; i >= 0; i--)
                {
                    Enemy enemy = currentTile.enemies[i];
                    double dir = randDouble(0,1);
                    if(dir >= 0 && dir < .25 && !currentTile.checkWall("left"))
                    {
                        if(!gameMap[x-1][y][currentFloor].containsPlayer())
                        {
                            gameMap[x-1][y][currentFloor].enemyIn(enemy);
                            gameMap[x][y][currentFloor].enemyOut(enemy);
                        }
                    }
                    else if(dir >= .25 && dir < .50 && !currentTile.checkWall("right"))
                    {
                        if(!gameMap[x+1][y][currentFloor].containsPlayer())
                        {
                            gameMap[x+1][y][currentFloor].enemyIn(enemy);
                            gameMap[x][y][currentFloor].enemyOut(enemy);
                        }
                    }
                    else if(dir >= .50 && dir < .75 && !currentTile.checkWall("up"))
                    {
                        if(!gameMap[x][y-1][currentFloor].containsPlayer())
                        {
                            gameMap[x][y-1][currentFloor].enemyIn(enemy);
                            gameMap[x][y][currentFloor].enemyOut(enemy);
                        }
                    }
                    else if(dir >= .75 && dir < 1 && !currentTile.checkWall("down"))
                    {
                        if(!gameMap[x][y+1][currentFloor].containsPlayer())
                        {
                            gameMap[x][y+1][currentFloor].enemyIn(enemy);
                            gameMap[x][y][currentFloor].enemyOut(enemy);
                        }
                    }
                }
            }
        }
    }
}

Tile& Map::playerTile()
{
    return getTile(playerX, playerY, playerZ);
}

void Map::displayEnemiesInPlayerTile()
{
    Tile t = playerTile();
    for(int i = 0; i < t.enemies.size(); i++)
    {
        cout << "\t" << i+1 << ". " << t.enemies[i] << endl;
    }
}

void Map::displayItemsInPlayerTile()
{
    Tile t = playerTile();
    for(int i = 0; i < t.items.size(); i++)
    {
        cout << "\t" << i+1 << ". " << t.items[i] << endl;
    }
}
