#ifndef TILE_H
#define TILE_H

#include <vector>

//TODO: Make vector have monster type
class Tile
{
    public:
        Tile();

        std::vector<int> getMonsters() { return monsters; }
        void addToMonsters(int val) { monsters.push_back(val); }

        int getCaps() { return caps; }
        void setCaps(int val) { caps = val; }

        bool containsElevator() { return elevator; }
        void makeElevator() { elevator = true; }

        bool containsPlayer() { return player; }
        void playerIn() { player = true; }
        void playerOut() { player = false; }

    protected:

    private:
        // Monsters currently in room
        std::vector<int> monsters;
        int caps;
        bool elevator;
        bool player;
};

#endif // TILE_H
