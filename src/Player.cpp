#include "../include/Player.h"
#include "../include/Commands.h"
#include <iostream>
#include <algorithm>
#include <vector>

void Player::runCharacterCreation(const bool DEBUG)
{
    // If debug is turned on, skip character setup for testing other things
    if(!DEBUG)
    {
        cout << "Welcome to Escape the Vault.\n";
        cout << "You wake up, cold and confused. You start to remember who you are...\n";

        std::string input;
        std::cout << "Who am I?\n";
        std::cin >> input;
        setName(input);
        std::cout << "How old am I?\n";
        std::cin >> input;
        setAge(stoi(input));
        std::cout << "What am I skilled in?\n";
        std::cout << "In strength, perception, endurance, charisma, intelligence, agility, luck?\n";
        std::cout << "(5 points to each by default)\n";
        int pointsLeft = 5;
        std::cout << pointsLeft << " points left to assign. Current distribution:\n\tStrength: " << getStrength() << " Perception: " << getPerception() << " Endurance: " << getEndurance() << " Charisma: " << getCharisma() << "\n\tIntelligence: " << getIntelligence() << " Agility: " << getAgility() << " Luck: " << getLuck() << std::endl;
        while(pointsLeft > 0)
        {
            std::cin >> input;
            for(int i = 0; i < input.size(); i++)
            {
                input[i] = tolower(input[i]);
            }
            if(input == "strength" || input == "s")
            {
                setStrength(getStrength()+1);
                pointsLeft--;
            }
            else if(input == "perception" || input == "p")
            {
                setPerception(getPerception()+1);
                pointsLeft--;
            }
            else if(input == "endurance" || input == "e")
            {
                setEndurance(getEndurance()+1);
                pointsLeft--;
            }
            else if(input == "charisma" || input == "c")
            {
                setCharisma(getCharisma()+1);
                pointsLeft--;
            }
            else if(input == "intelligence" || input == "i")
            {
                setIntelligence(getIntelligence()+1);
                pointsLeft--;
            }
            else if(input == "agility" || input == "a")
            {
                setAgility(getAgility()+1);
                pointsLeft--;
            }
            else if(input == "luck" || input == "l")
            {
                setLuck(getLuck()+1);
                pointsLeft--;
            }
            else
                std::cout << "Please try again.\n";
            std::cout << pointsLeft << " points left to assign. Current distribution:\n\tStrength: " << getStrength() << " Perception: " << getPerception() << " Endurance: " << getEndurance() << " Charisma: " << getCharisma() << "\n\tIntelligence: " << getIntelligence() << " Agility: " << getAgility() << " Luck: " << getLuck() << std::endl;
        }

        cout << "\nYou clamber out of the cryochamber and start your journey out of the vault...\n";
        system(pauseCommand.c_str());
        system(clsCommand.c_str());
    }
    else
    {
        setName("Vault Boy");
        setAge(17);
        setStrength(getStrength()+2);
        setEndurance(getEndurance()+1);
        setAgility(getAgility()+1);
        setIntelligence(getIntelligence()+1);
    }
}

void Player::displayInventory()
{
    std::vector<Item> displayOnce;
    for(int i = 0; i < inventory.getNumItems(); i++)
    {
        Item currentItem = inventory[i];
        int numSame = inventory.count(currentItem);
        if(numSame == 1)
        {
            std::cout << "\t" << i+1 << ". " << inventory[i] << std::endl;
        }
        else if(std::find(displayOnce.begin(), displayOnce.end(), currentItem) == displayOnce.end())
        {
            displayOnce.push_back(currentItem);
            std::cout << "\t" << i+1 << ". " << inventory[i] << " (x" << numSame << ")" << std::endl;
        }
    }
}

void Player::fillInventory()//to be used for demonstration to show that crafting works , will fill inventory with crafting reagents, call it with "fillInventory"
{
    for(int i = 0; i < 3; i++)
   {
       addToInventory(Item("Blood Pack"));
       addToInventory(Item("Steel"));
       addToInventory(Item("Leather"));
       addToInventory(Item("Claw"));
       addToInventory(Item("Buckles"));
   }
    addToInventory(Item("Mini Nuke"));
    addToInventory(Item("Heavy Armor"));
    addToInventory(Item("Stimpak"));
}

bool Player::use(int idx)
{
    Item toUse = inventory[idx];

    if(toUse.itemType == "RECOVERY")
    {
        hp += toUse.hpRestore;
        removeFromInventory(toUse);
        cout << "Restored " << toUse.hpRestore << " hp.\n";
        system(pauseCommand.c_str());
        return true;
    }
    else return false;
}
