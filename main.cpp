#include <iostream>
#include <string>
#include <cstdlib>
#include "include/Player.h"
#include "include/Map.h"
using namespace std;

void displayCommands()
{
    system("cls");
    cout << "[w] north: move north\n";
    cout << "[s] south: move south\n";
    cout << "[a] west: move west\n";
    cout << "[d] east: move east\n";
    cout << "[q] help: display the list of valid commands\n";
    cout << "[x] quit: quit the game\n";
    system("pause");
}

// A function to strip non-alphabetic characters from the start and end of the string.
// It will also convert all the remaining characters into lowercase.
string clean(const string& s)
{
    string r = "";
    for (int start = 0; start < s.length(); start++)
    {
        if (isalpha(s[start]))
        {
            for (int end = s.length()-1; end >= start; end--)
            {
                if (isalpha(s[end]))
                {
                    r = s.substr(start, end - start + 1);
                    break;
                }
            }
            break;
        }
    }

    for(int i = 0; i < r.size(); i++) {
        r[i] = tolower(r[i]);
    }

    return r;
}

int main()
{
    const bool DEBUG = true;

    int rows = 10, cols = 10, floors = 10;
    int startingX = 0, startingY = 0, startingZ = 9;
    double monsterSpawnRate = .05;
    Player pchar(startingX, startingY, startingZ);
    pchar.runCharacterCreation(DEBUG);
    Map gameMap(monsterSpawnRate, rows, cols, floors, startingX, startingY, startingZ);

    string input = "";
    while(input != "quit" && input != "x") {
        gameMap.print();
        Tile currentTile = gameMap.playerTile();
        cout << "Walls: ";
        if(currentTile.checkWall("up")) cout << " north ";
        if(currentTile.checkWall("down")) cout << " south ";
        if(currentTile.checkWall("left")) cout << " west ";
        if(currentTile.checkWall("right")) cout << " east ";

        cout << "\nPlease enter a command.\n";
        cin >> input;
        input = clean(input);
        if((input == "up" || input == "north" || input == "w") && !currentTile.checkWall("up"))
        {
            pchar.moveUp();
        }
        else if((input == "down" || input == "south" || input == "s") && !currentTile.checkWall("down"))
        {
            pchar.moveDown();
        }
        else if((input == "left" || input == "west" || input == "a") && !currentTile.checkWall("left"))
        {
            pchar.moveLeft();
        }
        else if((input == "right" || input == "east" || input == "d") && !currentTile.checkWall("right"))
        {
            pchar.moveRight();
        }
        else if(input == "help" || input == "q")
        {
            displayCommands();
        }
        else if(input != "x")
        {
            cout << "Invalid command.\n";
            displayCommands();
        }

        gameMap.updatePlayerLoc(pchar.getX(), pchar.getY(), pchar.getZ());
        gameMap.updateMonsterLocs();

        system("cls");
    }

    return 0;
}
