#include <iostream>
#include <string>
#include <cstdlib>
#include "include/Player.h"
#include "include/Map.h"
using namespace std;

int main()
{
    const bool DEBUG = true;

    int rows = 10, cols = 10, floors = 10;
    int startingX = 0, startingY = 0, startingZ = 9;
    Player pchar(startingX, startingY, startingZ);
    pchar.runCharacterCreation(DEBUG);
    Map gameMap(rows, cols, floors, startingX, startingY, startingZ);

    string input = "";
    while(input != "quit") {
        gameMap.print();
        Tile currentTile = gameMap.playerTile();
        cout << "Walls: ";
        if(currentTile.checkWall("up")) cout << " north ";
        if(currentTile.checkWall("down")) cout << " south ";
        if(currentTile.checkWall("left")) cout << " west ";
        if(currentTile.checkWall("right")) cout << " east ";

        cout << "\nPlease enter a command.\n";
        cin >> input;
        for(int i = 0; i < input.size(); i++) {
            input[i] = tolower(input[i]);
        }
        if(input == "up" && !currentTile.checkWall("up"))
        {
            pchar.moveUp();
        }
        else if(input == "down" && !currentTile.checkWall("down"))
        {
            pchar.moveDown();
        }
        else if(input == "left" && !currentTile.checkWall("left"))
        {
            pchar.moveLeft();
        }
//        else if(input == "right" && !currentTile.checkWall("right"))
        else if(input == "right" && !currentTile.checkWall("right"))
        {
            pchar.moveRight();
        }

        gameMap.updatePlayerLoc(pchar.getX(), pchar.getY(), pchar.getZ());

        system("cls");
    }

    return 0;
}
