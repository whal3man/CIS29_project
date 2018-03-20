#include "../include/Item.h"
#include "../include/Map.h"
#include "../include/Commands.h"
#include <vector>
#include <iostream>
#include <iomanip>

Map::Map(int rows_, int cols_, int floors_, int startingX, int startingY, int startingZ, double monsterSpawnRate_, double chestSpawnRate_)
{
    // Settings not important enough to include in constructor
    int maxMonsterHP = 100;
    int minMonsterHP = 80;
    int maxMonsterCaps = 60;
    int minMonsterCaps = 20;
    int minItemsPerChest = 3;
    int maxItemsPerChest = 6;

    monsterSpawnRate = monsterSpawnRate_;
    chestSpawnRate = chestSpawnRate_;

    rowCount = rows_;
    colCount = cols_;
    floorCount = floors_;

    playerX = playerStartingX = startingX;
    playerY = playerStartingY = startingY;
    playerZ = playerStartingZ = startingZ;
    currentFloor = startingZ;

    gameMap.resize(cols_,std::vector<std::vector<Tile>>(rows_,std::vector<Tile>(floors_)));
    // Generating a puzzle (minesweeper) room
    // Elevator choice is restricted to only the top of the room
    int elevatorX = randInt(0, cols_-1);
    int elevatorY = 0;
    double mineSpawnRate = 0.20;

    int z = 0;
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
            else if(x == elevatorX && y == elevatorY)
                t.makeElevator();
            else
            {
                // Generate mines
                if(y > 0 && y < rows_ - 1 && randDouble(0, 1) <= mineSpawnRate)
                    t.makeMine();
            }
            setTile(x, y, z, t);
        }
    }
    // Generate the number hints
    for(int y = 1; y < rows_ - 1; y++)
    {
        for(int x = 0; x < cols_; x++)
        {
            int numMines = 0;
            Tile tile = getTile(x, y, z);
            for(int x2 = x - 1; x2 < x + 2; x2++)
            {
                for(int y2 = y - 1; y2 < y + 2; y2++)
                {
                    if(x2 >= 0 && x2 < colCount && y2 >= 0 && y2 < rowCount
                            && getTile(x2, y2, z).isMine())
                    {
                        numMines++;
                    }
                }

            }
            if (numMines != 0 && !tile.isMine())
                    getTile(x, y, z).makeMinesweeperNumber(numMines);
        }
    }

    //Generating the rest of the levels.
    for(z = 1; z < floors_; z++)
    {
        // Elevator choice
        //The room before the puzzle room can only
        //have the elevator at the bottom of the room
        int elevatorX = randInt(0, cols_-1);
        if (z != 1)
            elevatorY = randInt(0, rows_-1);
        else
            elevatorY = rowCount - 1;

        // Merchant choice
        // One per floor that isn't the last floor
        // Can't be in the same tile as an elevator
        // (Except in a 1x1 floor)
        int merchantX, merchantY;
        if (z != 0)
        {
            merchantX = randInt(0, cols_-1);
            merchantY = randInt(0, rows_-1);
            if(cols_ != 1 && rows_ != 1)
            {
                while(merchantX == elevatorX && merchantY == elevatorY)
                {
                    merchantX = randInt(0, cols_-1);
                    merchantY = randInt(0, rows_-1);
                }
            }
        }

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
                else if(x == elevatorX && y == elevatorY)
                    t.makeElevator();
                else if(z != 0 && x == merchantX && y == merchantY)
                    t.makeMerchant();
                else
                {
                    // Monster Generation
                    // Some bits randomly created
                    if(randDouble(0,1) < monsterSpawnRate)
                    {
                        vector<Item> loot; // Need to fill this
                        int randWeaponIdx = randInt(0, Item::possibleWeapons.size()-1);
                        Item randomWeapon = Item::possibleWeapons[randWeaponIdx];
                        loot.push_back(randomWeapon);
                        int s = Enemy::possibleNames.size();
                        int randIndex = randInt(0, s-1);
                        int randDist = randInt(0, 3);
                        int nx = x, ny = y;
                        if (randInt(0, 1) == 0)
                        {
                            if (randInt(0, 1) == 0)
                                nx -= randDist;
                            else
                                nx += randDist;
                            if (nx < 0)
                                nx = 0;
                            else if (nx > cols_ - 1)
                                nx = cols_ - 1;
                        }
                        else
                        {
                            if (randInt(0, 1) == 0)
                                ny -= randDist;
                            else
                                ny += randDist;
                            if (ny < 0)
                                ny = 0;
                            else if (ny > rows_ - 1)
                                ny = rows_ - 1;
                        }
                        std::string newEnemyName = Enemy::possibleNames[randIndex];
                        int randHP = randInt(minMonsterHP, maxMonsterHP);
                        int randCaps = randInt(minMonsterCaps, maxMonsterCaps);
                        Enemy newEnemy(x, y, z, nx, ny, newEnemyName, randHP, loot, randCaps);
                        t.enemyIn(newEnemy);
                    }

                    // Item Generation
                    // Every healthkit/rifle/whatever is the exact same, so preset list
                    if(randDouble(0,1) < chestSpawnRate)
                    {
                        int numItems = randInt(minItemsPerChest, maxItemsPerChest);
                        for(int i = 0; i < numItems; i++)
                        {
                            int s = Item::possibleItems.size();
                            int randIndex = randInt(0, s-1);
                            Item newItem = Item::possibleItems[randIndex];
                            t.addItem(newItem);
                        }
                        t.makeChest();
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
            else if(currentTile.containsEnemy())
                std::cout << std::setw(spacesBetweenTiles) << "[M]";
            else if(currentTile.containsMerchant())
                std::cout << std::setw(spacesBetweenTiles) << "[V]";
            else if(currentTile.containsElevator())
                std::cout << std::setw(spacesBetweenTiles) << "[E]";
            else if(currentTile.isChest())
                std::cout << std::setw(spacesBetweenTiles) << "[C]";
            else if(currentTile.containsItem())
                std::cout << std::setw(spacesBetweenTiles) << "[I]";
            else if(currentTile.isMine() && currentTile.isRevealed())
                std::cout << std::setw(spacesBetweenTiles) << "[*]";
            else if(currentTile.isMinesweeperNumber() && currentTile.isRevealed())
            {
                std::string display = "[" + std::to_string(currentTile.getNumAdjacentMines()) + "]";
                std:: cout << std::setw(spacesBetweenTiles) << display;
            }

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

    if (gameMap[x][y][z].checkWall(enemy.getDir()))
        return false;
    if (nx < enemy.getAX() || nx > enemy.getBX())
        return false;
    if (ny < enemy.getAY() || ny > enemy.getBY())
        return false;

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

            if(currentTile.containsEnemy() && x != playerX && y != playerY)
            {
                int numEnemies = currentTile.getNumEnemies();
                for(int i = numEnemies-1; i >= 0; i--)
                {
                    Enemy& enemy = currentTile.enemies[i];

                    if(randDouble(0, 1) < 0.5) // 50% chance to not move
                    {
                        // 50% chance to either move randomly or in a direction until it hits something
                        if(randDouble(0, 1) > 1)
                        {
                            if (enemy.allowMove)
                            {
                                // If movement fails for whatever reason, reverse direction.
                                if (moveEnemy(enemy) == false)
                                {
                                    currentTile.enemies[i].revDir();
                                }
                            }
                        }
                        else
                        {
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

void Map::checkEnemyDeaths()
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
                    Enemy& enemy = currentTile.enemies[i];

                    if(!enemy.isAlive())
                    {
                        Inventory loot = enemy.getLoot();
                        currentTile.enemyOut(enemy);
                        for(int k = 0; k < loot.size(); k++)
                        {
                            currentTile.addItem(loot[k]);
                        }
                    }
                }
            }
        }
    }
}

void Map::checkEnemyAttacks(Player& player)
{
    if(playerTile().containsEnemy())
    {
        int numEnemies = playerTile().getNumEnemies();
        for(int i = numEnemies-1; i >= 0; i--)
        {
            Enemy enemy = playerTile().enemies[i];

            if(enemy.isAlive())
            {
                int damageDone = enemy.attack(player);
                cout << "\nWas dealt " << damageDone << " damage from " << enemy.name << endl;
                system(pauseCommand.c_str());
            }
        }
    }
}

void Map::checkMine(Player& player)
{
    if(playerTile().isMine() && !playerTile().isRevealed())
    {
        playerTile().makeRevealed();
        cout << "\nYou step on a trap and take " << player.takeDamage(10) << " damage." << endl;
        system(pauseCommand.c_str());
    }
}

void Map::checkMinesweeperNumbers()
{
    for(int x = playerX - 1; x < playerX + 2; x++)
    {
        for(int y = playerY - 1; y < playerY + 2; y++)
        {
            if(x >= 0 && x < colCount && y >= 0 && y < rowCount)
            {
                Tile tile = getTile(x, y, playerZ);
                if(tile.isMinesweeperNumber() && !tile.isRevealed())
                    getTile(x, y, playerZ).makeRevealed();
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
    if(t.isChest())
    {
        cout << "\tUnlock this chest with \"[l]\" to view its contents\n";
    }
    else
    {
        for(int i = 0; i < t.items.size(); i++)
        {
            cout << "\t" << i+1 << ". " << t.items[i] << endl;
        }
    }
}
