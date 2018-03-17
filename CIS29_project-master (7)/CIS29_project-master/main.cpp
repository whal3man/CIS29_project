#include <iostream>
#include <string>
#include <cstdlib>
#include "include/Player.h"
#include "include/Map.h"
#include "include/Inventory.h"
#include "include/Item.h"
#include <iomanip>
using namespace std;

void displayHelp()
{
    system("cls");
    cout << "Tile codes: [P] = Player. [M] = Enemy. [I] = Item. [E] = Elevator. \nCommands:\n";
    cout << "[w] north: move north\n";
    cout << "[s] south: move south\n";
    cout << "[a] west: move west\n";
    cout << "[d] east: move east\n";
    cout << "[v] elevator: use an elevator to travel up a floor\n";
    cout << "[p] pick: pick up an item\n";
    cout << "[e] equip: equip an item\n";
    cout << "[u] unequip: unequip an item\n";
    cout << "[f] attack: attack an enemy\n";
    cout << "[q] help: display the list of valid commands\n";
    cout << "[c] open to crafting menu\n";
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
void createCraftedItems()
{
    //Item(std::string itemName_, std::string itemType_, int itemValue = 10, int sellValue = 10, int buyValue = 10);
    Item stimpak;
    stimpak.setItemName("stimpak");
    stimpak.setHealingValue(15);
    stimpak.setSellValue(10);
    stimpak.setBuyValue(10);
    Item Steel;
}
void fillInventory()//to be used for demonstration to show that crafting works , will fill inventory with crafting reagents, call it with "fillInventory"
{
Item reagentBloodPack("BloodPack","",5,5,5);
Item reagentSteel("Steel","",5,5,5);


}
void displayCraftableItems(Inventory& obj)
{
    system("cls");
string option;
cout << "List of items that can be crafted: " <<endl;
cout <<setw(20)<<left <<"ITEM"<<setw(5) <<"|" << "REAGENTS NEEDED" <<setw(10)<<endl;
cout << "-----------------------------------------------------------------------------\n";
cout <<setw(20)<<left <<"Stimpak"<<setw(5) <<"|" << "Blood Pack , Steel" <<endl;
cout <<setw(20)<< left<<"DeathClaw Gauntlet"<<setw(5) <<"|" << "Leather , Steel , Claw" <<endl;
cout <<setw(20)<< left<<"ShishKebab"<<setw(5) <<"|" << "Steel , Leather , Gas Container" <<endl;
cout <<setw(20)<< left<<"Shortsword"<<setw(5) <<"|" << "Steel, Leather" <<endl;
cout <<setw(20)<< left<<"Longsword"<<setw(5) <<"|" << "Steel , Leather" <<endl;
cout <<setw(20)<< left<<"Light Armor"<<setw(5) <<"|" << "Leather , Buckles" <<endl;
cout <<setw(20)<< left<<"Heavy Armor"<<setw(5) <<"|" << "Steel , Buckles" <<endl;

cout << "\nWhat would you like to craft? type e to exit \n" <<endl;
cin >> option;
if(option == "e")
    {
        cout << "returning to menu\n";

}
else{
obj.craft(option);
system("pause");
}

}
int main()
{

    const bool DEBUG = true;

    // Map generation settings
    int rows = 5, cols = 5, floors = 2;
    int startingX = 0, startingY = 0, startingZ = floors-1;
    double monsterSpawnRate = .10;
    double itemSpawnRate = .25;
    Player pchar(startingX, startingY, startingZ);
    pchar.runCharacterCreation(DEBUG);
    Map gameMap(rows, cols, floors, startingX, startingY, startingZ, monsterSpawnRate, itemSpawnRate);

    string input = "";
    while(input != "quit" && input != "x" && !pchar.wonGame()) {
        gameMap.print();
        Tile currentTile = gameMap.playerTile();
        cout << "Walls: ";
        if(currentTile.checkWall("up")) cout << " north ";
        if(currentTile.checkWall("down")) cout << " south ";
        if(currentTile.checkWall("left")) cout << " west ";
        if(currentTile.checkWall("right")) cout << " east ";

        cout << "\nEnemies in tile: \n";
        gameMap.displayEnemiesInPlayerTile();

        cout << "\nItems in tile: \n";
        gameMap.displayItemsInPlayerTile();

        cout << "\nPlayer inventory: \n";
        pchar.displayInventory();

        cout << "\nItem equipped: \n\t";
        cout << pchar.getEquippedItem() << endl;

        cout << "\nPlease enter a command. (\"help\" or \"q\" for help)\n";
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
        else if((input == "elevator" || input == "v") && currentTile.containsElevator())
        {
            pchar.goUpFloor();
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
        else if((input == "unequip" || input == "u") && pchar.getEquippedItem() != pchar.defaultItem)
        {
            pchar.unequip();
        }
        else if((input == "attack" || input == "fight" || input == "f") && currentTile.containsEnemy() && pchar.getEquippedItem() != pchar.defaultItem)
        {
            int enemyNumber;
            cout << "Please enter the list number of the enemy to attack (0 to cancel). ";
            cin >> enemyNumber;
            int idx = enemyNumber-1;
            if(idx >= 0 && idx < gameMap.playerTile().getNumEnemies())
            {
                pchar.attack(gameMap.playerTile().getEnemy(idx));
            }
        }
        else if(input == "help" || input == "q")
        {
            displayHelp();
        }
        else if (input == "c" || input == "craft" || input == "Crafting")
        {
            displayCraftableItems(pchar.inventory);
        }
        else if (input == "fill")
        {
            cout << "you just cheated .. tsktsk\n";
            Item Steel("Steel","",0,0,0);
            Item Leather("Leather","",0,0,0);
            Item BloodPack("Blood Pack","",0,0,0);
            pchar.addToInventory(BloodPack);
            pchar.addToInventory(Steel);
            pchar.addToInventory(Leather);
            system("pause");
        }
        else if(input == "x")
        {
            system("cls");
            cout << "Thanks for playing!";
        }

        gameMap.updatePlayerLoc(pchar.getX(), pchar.getY(), pchar.getZ());

        gameMap.updateEnemyLocs();

        system("cls");
    }

    if(pchar.wonGame())
    {
        cout << "~~~~~~~~ You win! Great job! Thanks for playing. ~~~~~~~~ \nStats: ";
        cout << pchar;
    }

    return 0;
}
