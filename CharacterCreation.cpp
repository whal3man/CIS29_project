#include <iostream>
#include <string>
#include "include/Character.h"
using namespace std;

void runCharacterCreation(Character pchar)
{
    string input;
    cout << "Who am I?\n";
    cin >> input;
    pchar.setName(input);
    cout << "How old am I?\n";
    cin >> input;
    pchar.setAge(stoi(input));

    cout << "What am I skilled in?\n";
    cout << "In strength, perception, endurance, charisma, intelligence, agility, luck?\n";
    cout << "(5 points to each by default)\n";
    int pointsLeft = 5;
    cout << pointsLeft << " points left to assign. Current distribution:\n\tStrength: " << pchar.getStrength() << " Perception: " << pchar.getPerception() << " Endurance: " << pchar.getEndurance() << " Charisma: " << pchar.getCharisma() << "\n\tIntelligence: " << pchar.getIntelligence() << " Agility: " << pchar.getAgility() << " Luck: " << pchar.getLuck() << endl;
    while(pointsLeft > 0)
    {
        cin >> input;
        for(int i = 0; i < input.size(); i++)
        {
            input[i] = tolower(input[i]);
        }
        if(input == "strength" || input == "s")
        {
            pchar.setStrength(pchar.getStrength()+1);
            pointsLeft--;
        }
        else if(input == "perception" || input == "p")
        {
            pchar.setPerception(pchar.getPerception()+1);
            pointsLeft--;
        }
        else if(input == "endurance" || input == "e")
        {
            pchar.setEndurance(pchar.getEndurance()+1);
            pointsLeft--;
        }
        else if(input == "charisma" || input == "c")
        {
            pchar.setCharisma(pchar.getCharisma()+1);
            pointsLeft--;
        }
        else if(input == "intelligence" || input == "i")
        {
            pchar.setIntelligence(pchar.getIntelligence()+1);
            pointsLeft--;
        }
        else if(input == "agility" || input == "a")
        {
            pchar.setAgility(pchar.getAgility()+1);
            pointsLeft--;
        }
        else if(input == "luck" || input == "l")
        {
            pchar.setLuck(pchar.getLuck()+1);
            pointsLeft--;
        }
        else cout << "Please try again.\n";
        cout << pointsLeft << " points left to assign. Current distribution:\n\tStrength: " << pchar.getStrength() << " Perception: " << pchar.getPerception() << " Endurance: " << pchar.getEndurance() << " Charisma: " << pchar.getCharisma() << "\n\tIntelligence: " << pchar.getIntelligence() << " Agility: " << pchar.getAgility() << " Luck: " << pchar.getLuck() << endl;
    }
}
