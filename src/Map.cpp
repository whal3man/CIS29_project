#include "../include/Map.h"
#include "../include/RandNumber.h"
#include <vector>
#include <iostream>
#include <iomanip>

const std::vector<Item> possibleItems = {Item("Hunting Rifle", "RANGED WEAPON"), Item("Large Club", "MELEE WEAPON")};// Item("Steel", "MATERIAL"), Item("Leather", "MATERIAL"), Item("Blood Pack", "MATERIAL"), Item("Claw", "MATERIAL"), Item("Gas Container", "MATERIAL"), Item("Leather Strip", "MATERIAL"), Item("Buckles", "MATERIAL"), Item("Small Hilt", "MATERIAL"), Item("Large Hilt", "MATERIAL")};

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
                    // Some bits randomly created, so no preset list in Map
                    if(randDouble(0,1) < monsterSpawnRate)
                    {
                        vector<Item> loot; // Need to fill this
                        int s = Enemy::possibleNames.size();
                        int randIndex = randInt(0, s-1);
                        int randDist = randInt(0, 3);
                        int nx = x, ny = y;
                        if (randInt(0, 1) == 0)
                        {
                            if (randInt(0, 1) == 0) nx -= randDist;
                            else nx += randDist;
                            if (nx < 0) nx = 0;
                            else if (nx > cols_ - 1) nx = cols_ - 1;
                        }
                        else
                        {
                            if (randInt(0, 1) == 0) ny -= randDist;
                            else ny += randDist;
                            if (ny < 0) ny = 0;
                            else if (ny > rows_ - 1) ny = rows_ - 1;
                        }
                        std::string newEnemyName = Enemy::possibleNames[randIndex];
                        int randHP = randInt(minMonsterHP, maxMonsterHP+1);
                        Enemy newEnemy(x, y, z, nx, ny, newEnemyName, randHP, loot);
                        t.enemyIn(newEnemy);
                        std::cout << "Enemy generated at (" << x << ", " << y << ", " << z
                                  << "); will move to (" << nx << ", " << ny << ", " << z << ")\n";
                    }

                    // Item Generation
                    // Every healthkit/rifle/whatever is the exact same, so preset list in Map
                    else if(randDouble(0,1) < itemSpawnRate)
                    {
                        int s = possibleItems.size();
                        int randIndex = randInt(0, s-1);
                        Item newItem = possibleItems[randIndex];
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

bool Map::moveEnemy(Enemy& enemy)
{
    int x = enemy.getX();
    int y = enemy.getY();
    int z = enemy.getZ();
    int nx = x + enemy.getDX();
    int ny = y + enemy.getDY();

    if (gameMap[x][y][z].checkWall(enemy.getDir())) return false;
    if (nx < enemy.getAX() || nx > enemy.getBX()) return false;
    if (ny < enemy.getAY() || ny > enemy.getBY()) return false;

    // Move the enemy.
    gameMap[x][y][z].enemyOut(enemy);
    enemy.setLoc(nx, ny);
    enemy.allowMove = false;
    gameMap[nx][ny][z].enemyIn(enemy);

    return true;
}

void Map::updateEnemyLocs()
{
    for(int y = 0; y < numRows(); y++)
    {
        for(int x = 0; x < numCols(); x++)
        {
            Tile& currentTile = getTile(x, y, currentFloor);

            if(currentTile.containsEnemy())
            {
                int numEnemies = currentTile.getNumEnemies();
                for(int i = numEnemies-1; i >= 0; i--)
                {
                    Enemy enemy = currentTile.enemies[i];

                    // If movement fails for whatever reason, reverse direction.
                    if (enemy.allowMove)
                    {
                        if (moveEnemy(enemy) == false)
                        {
                            currentTile.enemies[i].revDir();
                        }
                    }
                }
            }
        }
    }

    // Reset the movement flag.
    for(int y = 0; y < numRows(); y++)
    {
        for(int x = 0; x < numCols(); x++)
        {
            Tile& currentTile = getTile(x, y, currentFloor);

            if(currentTile.containsEnemy())
            {
                int numEnemies = currentTile.getNumEnemies();
                for(int i = numEnemies-1; i >= 0; i--)
                {
                    currentTile.enemies[i].allowMove = true;
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
