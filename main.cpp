#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include "include/Player.h"
#include "include/Map.h"
#include "include/Inventory.h"
#include "include/Item.h"
#include "include/Enemy.h"
#include "include/Minigames.h"
#include "include/Mastermind.h"
#include "include/BadInputException.h"
#include "include/Commands.h"
#include "RandNumber.h"
using namespace std;

namespace utility
{
    vector<string> validCommands = {"w", "a", "s", "d", "up", "down", "left", "right", "v", "elevator", "upe", "b", "buy", "p", "pick", "pick up", "l", "unlock", "lockpick", "e", "equip", "u", "unequip", "u", "use", "f", "fight", "attack", "c", "craft", "q", "help", "x", "exit", "wait", "fill", "kill", "givecaps"};

    void displayHelp() noexcept
    {
        system(clsCommand.c_str());
        cout << "Tile codes: [P] = Player. [M] = Enemy.  [V] = Merchant. [C] = Chest. [I] = Item. [E] = Elevator. \nCommands:\n";
        cout << "[w] north: move north\n";
        cout << "[s] south: move south\n";
        cout << "[a] west: move west\n";
        cout << "[d] east: move east\n";
        cout << "[v] elevator: use an elevator to travel up a floor\n";
        cout << "[b] buy: buy from Merchant\n";
        cout << "[p] pick: pick up an item\n";
        cout << "[l] unlock: try to unlock a chest\n";
        cout << "[e] equip: equip an item\n";
        cout << "[n] unequip: unequip an item\n";
        cout << "[u] use: attempt  to use an item\n";
        cout << "[f] attack: attack an enemy\n";
        cout << "[c] craft: open crafting menu\n";
        cout << "[q] help: display the list of valid commands\n";
        cout << "[x] quit: quit the game\n";
        cout << "Cheat codes:\n";
        cout << "fill: gives a bunch of goodies\n";
        cout << "kill: kill an enemy\n";
        cout << "givecaps: gives a bunch of caps\n";
        cout << "wait: pass time\n";

        system(pauseCommand.c_str());
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

        for(int i = 0; i < r.size(); i++)
        {
            r[i] = tolower(r[i]);
        }

        return r;
    }

    string getInput() throw(BadInputException)
    {
        string input;
        cin >> input;
        input = utility::clean(input);
        if(std::find(utility::validCommands.begin(), utility::validCommands.end(), input) == utility::validCommands.end()) throw(BadInputException(input));
        else return input;
    }
}

int main()
{

    const bool DEBUG = false;
    const bool moveEnemies = true;

    // Map generation settings
    int rows = 5, cols = 5, floors = 3;
    int startingX = 0, startingY = 0, startingZ = floors-1;
    double monsterSpawnRate = .20;
    double chestSpawnRate = .20;
    bool playAgain = true;
    while(playAgain = true)
    {
        Player pchar(startingX, startingY, startingZ);
        pchar.runCharacterCreation(DEBUG);
        Map gameMap(rows, cols, floors, startingX, startingY, startingZ, monsterSpawnRate, chestSpawnRate);

        string input = "";
        while(input != "quit" && input != "x" && !pchar.wonGame() && !pchar.lostGame())
        {
            gameMap.print();
            Tile& currentTile = gameMap.playerTile();
            cout << "Walls: ";
            if(currentTile.checkWall("up"))
                cout << " north ";
            if(currentTile.checkWall("down"))
                cout << " south ";
            if(currentTile.checkWall("left"))
                cout << " west ";
            if(currentTile.checkWall("right"))
                cout << " east ";

            cout << "\nEnemies in tile: \n";
            gameMap.displayEnemiesInPlayerTile();

            cout << "\nItems in tile: \n";
            gameMap.displayItemsInPlayerTile();

            cout << "\nPlayer inventory: \n";
            pchar.displayInventory();

            cout << "\nItems equipped: \n\t";
            cout << pchar.getEquippedWeapon() << endl;
            cout << "\t" << pchar.getEquippedArmor() << endl;

            cout << "\nPlayer stats:\n";
            cout << pchar << endl;

            currentTile.displayTileInfo();

            cout << "\nPlease enter a command. (\"help\" or \"q\" for help)\n";
            try {
                input = utility::getInput();
                bool justMoved = false;
                bool justMovedUp = false;
                bool inputWasValid = true;
                if((input == "up" || input == "north" || input == "w") && !currentTile.checkWall("up"))
                {
                    pchar.moveUp();
                    justMoved = true;
                }
                else if((input == "down" || input == "south" || input == "s") && !currentTile.checkWall("down"))
                {
                    pchar.moveDown();
                    justMoved = true;
                }
                else if((input == "left" || input == "west" || input == "a") && !currentTile.checkWall("left"))
                {
                    pchar.moveLeft();
                    justMoved = true;
                }
                else if((input == "right" || input == "east" || input == "d") && !currentTile.checkWall("right"))
                {
                    pchar.moveRight();
                    justMoved = true;
                }
                else if((input == "elevator" || input == "v" || input == "upe") && currentTile.containsElevator())
                {
                    pchar.goUpFloor();
                    justMoved = true;
                    justMovedUp = true;
                }
                else if((input == "l" || input == "unlock" || input == "lockpick") && currentTile.isChest())
                {
                    int rand = randInt(0, 10);
                    if (rand < 5)
                    {
                        int low = 0, high = 9;
                        if(guessingGame(low, high)) currentTile.unlockChest();
                    } else
                    {
                        rand = randInt(0, 9999);
                        Mastermind game = Mastermind(rand);
                        if (game.playGame()) currentTile.unlockChest();
                    }

                }
                else if((input == "pick up" || input == "pick" || input == "p") && currentTile.containsItem())
                {
                    int itemNumber;
                    cout << "Please enter the list number of the item to pick up (0 to cancel). ";
                    cin >> itemNumber;
                    int idx = itemNumber-1;
                    if(idx >= 0 && idx < gameMap.playerTile().getNumItems())
                    {
                        pchar.addToInventory(gameMap.playerTile().getItem(idx));
                        gameMap.playerTile().removeItem(idx);
                    }
                }
                else if((input == "equip" || input == "e") && pchar.hasItemsInInventory())
                {
                    int itemNumber;
                    cout << "Please enter the list number of the item to equip (0 to cancel). ";
                    cin >> itemNumber;
                    int idx = itemNumber-1;
                    if(idx >= 0 && idx < pchar.numItemsInInventory())
                    {
                        pchar.equip(idx);
                    }
                }
                else if(input == "unequip" || input == "n")
                {
                    int itemNumber;
                    cout << "Please enter the list number of the item to unequip (0 to cancel). ";
                    cin >> itemNumber;
                    int idx = itemNumber-1;
                    if(idx == 0 || idx == 1)
                    {
                        pchar.unequip(idx);
                    }
                }
                else if(input == "use" || input == "u")
                {
                    int itemNumber;
                    cout << "Please enter the list number of the item to use (0 to cancel). ";
                    cin >> itemNumber;
                    int idx = itemNumber-1;
                    if(idx >= 0 && idx < pchar.inventory.size())
                    {
                        if(!pchar.use(idx))
                        {
                            cout << "\nCan't use that.\n";
                            system(pauseCommand.c_str());
                        }
                    }
                }
                else if((input == "attack" || input == "fight" || input == "f") && currentTile.containsEnemy())
                {
                    int enemyNumber;
                    cout << "Please enter the list number of the enemy to attack (0 to cancel). ";
                    cin >> enemyNumber;
                    int idx = enemyNumber-1;
                    if(idx >= 0 && idx < gameMap.playerTile().getNumEnemies())
                    {
                        Enemy& enemy = gameMap.playerTile().getEnemy(idx);
                        pchar.attack(enemy);
                    }
                }
               else if ((input == "buy" || input == "b") && currentTile.containsMerchant())
                {
                    currentTile.vendor.runTheMerch(pchar);
                }
                else if(input == "help" || input == "q")
                {
                    utility::displayHelp();
                }
                else if (input == "c" || input == "craft" || input == "Crafting")
                {
                    string choice = pchar.inventory.getCraftingChoice(); // "e" to exit
                    if(choice != "e")
                    {
                        pchar.inventory.craft(choice);
                    }
                }
                else if (input == "fill")
                {
                    pchar.fillInventory();
                }
                else if (input == "kill")
                {
                    int enemyNumber;
                    cout << "Please enter the list number of the enemy to kill (0 to cancel). ";
                    cin >> enemyNumber;
                    int idx = enemyNumber-1;
                    if(idx >= 0 && idx < gameMap.playerTile().getNumEnemies())
                    {
                        Enemy& enemy = gameMap.playerTile().getEnemy(idx);
                        int damageDone = pchar.attack(enemy, true);
                    }
                }
                else if (input == "givecaps")
                {
                    pchar.inventory.setCaps(9999999);
                }
                else if (input == "wait")
                {
                    // Literally nothing
                }
                else if(input == "x")
                {
                    system(clsCommand.c_str());
                    cout << "Thanks for playing!";
                }
                else inputWasValid = false;


                gameMap.checkEnemyDeaths();

                gameMap.updatePlayerLoc(pchar.getX(), pchar.getY(), pchar.getZ());

                if(justMoved && !justMovedUp)
                {
                    gameMap.checkMine(pchar);
                    gameMap.checkMinesweeperNumbers();
                }

                if(moveEnemies && inputWasValid) gameMap.updateEnemyLocs();

                if(!justMoved && inputWasValid) gameMap.checkEnemyAttacks(pchar);

            }
            catch(BadInputException e)
            {
                cout << e.what();
                system(pauseCommand.c_str());
            }
            system(clsCommand.c_str());
        }

        if(pchar.wonGame())
        {
            cout << "~~~~~~~~ You win! Great job! Thanks for playing. ~~~~~~~~ \nStats: ";
            cout << pchar << endl;
        }
        else if(pchar.lostGame())
        {
            cout << "~~~~~~~~ You lost! Good try! Thanks for playing. ~~~~~~~~ \nStats: ";
            cout << pchar << endl;
        }

        input = "";
        while(input != "y" && input != "n")
        {
            cout << "Would you like to play again? (y/n)\n";
            cin >> input;
            input = utility::clean(input);
            cout << "Error: invalid input.\n";
        }
        if(input == "y")
        {
            playAgain = true;
        }
        else if(input == "n")
        {
            playAgain = false;
        }
    }

    return 0;
}
