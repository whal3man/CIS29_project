#ifndef TILE_H
#define TILE_H

#include <vector>
#include <map>

class Tile
{
    public:
        Tile();

        int getCaps() { return caps; }
        void setCaps(int val) { caps = val; }

        bool containsElevator() { return elevator; }
        void makeElevator() { elevator = true; }

        bool containsPlayer() { return player; }
        void playerIn() { player = true; }
        void playerOut() { player = false; }

        bool containsMonster() { return monster; }
        void monsterIn() { monster = true; }
        void monsterOut() { monster = false; }

        void setWall(std::string dir, bool val = true) { walls[dir] = val; }
        bool checkWall(std::string dir) { return walls[dir]; }

    protected:

    private:
        int caps;
        bool elevator;
        bool player;
        bool monster;
        std::map<std::string, bool> walls;
};

#endif // TILE_H
