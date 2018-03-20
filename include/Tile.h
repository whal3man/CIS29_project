#ifndef TILE_H
#define TILE_H

#include "../include/Enemy.h"
#include "../include/Item.h"
#include "../include/Merchant.h"
#include "RandNumber.h"
#include <vector>
#include <map>

class Tile
{
    public:
        Tile();
        Tile(int mines);

        int getCaps() { return caps; }
        void setCaps(int val) { caps = val; }

        bool containsElevator() { return elevator; }
        void makeElevator() { elevator = true; }

    	bool containsMerchant() { return merchant; }
	    void makeMerchant() { merchant = true; }

        bool isChest() { return chest; }
        void makeChest() { chest = true; }
        void unlockChest() { chest = false; }

        bool isMine() { return mine; }
        void makeMine() { mine = true; }
        bool isMinesweeperNumber() { return minesweeperNumber; }
        void makeMinesweeperNumber(int number);
        int getNumAdjacentMines() { return numAdjacentMines; }
        bool isRevealed() { return revealed; }
        void makeRevealed() { revealed = true; }

        bool containsPlayer() { return player; }
        void playerIn() { player = true; }
        void playerOut() { player = false; }

        bool containsEnemy() { return enemies.size() != 0; }
        void enemyIn(Enemy e) { enemies.push_back(e); }
        void enemyOut(const Enemy& e);
        Enemy& getEnemy(int i) { return enemies[i]; }
        int getNumEnemies() { return enemies.size(); }

        bool containsItem() { return (items.size() != 0); }
        void addItem(Item i) { items.push_back(i); }
        void removeItem(const Item& i);
        void removeItem(int i);
        Item& getItem(int i) { return items[i]; }
        int getNumItems() { return items.size(); }

        void setWall(std::string dir, bool val = true) { walls[dir] = val; }
        bool checkWall(std::string dir) { return walls[dir]; }

        void displayTileInfo();

        std::vector<Enemy> enemies;
        std::vector<Item> items;
        int caps;
        bool elevator;
        bool player;
    	bool merchant;
    	Merchant vendor;
        bool chest;
        bool mine;
        bool minesweeperNumber;
        int numAdjacentMines;
        bool revealed;
        std::map<std::string, bool> walls;
};

#endif // TILE_H
