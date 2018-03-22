#include "../include/Mastermind.h"
#include "../include/Commands.h"
#include <iostream>
using namespace std;

Mastermind::Mastermind(int code_) : rows(10)
{
    int missingZeroes = 0;
    if (code_ < 10)
        missingZeroes = 1;
    else if (code_ < 100)
        missingZeroes = 2;
    else if (code_ < 1000)
        missingZeroes = 3;
    mastercode = to_string(code_);
    while (missingZeroes > 0)
    {
        mastercode.insert(0, "0");
        missingZeroes--;
    }

    board = new string[rows];
}

Mastermind::Mastermind(string code_) : mastercode(code_), rows(10)
{
    board = new string[rows];
}

Mastermind::Mastermind(int rows_, string code_) : rows(rows_), mastercode(code_)
{
    board = new string[rows];
}

Mastermind::~Mastermind()
{
    delete[] board;
}

bool Mastermind::playGame()
{
    string input;
    bool isCracked = false;
    int currRound = 0;

    while(!isCracked && currRound < rows)
    {
        printBoard();
        cout << "\nYou have " << rows - currRound << " guesses remaining." << endl;
        input = getInput();
        if(input == "mmbk" || input == mastercode)
        {
            isCracked = true;
            break;
        }
        if(stoi(input) < 0)
            break;
        board[currRound] = input;

        currRound++;
    }
    printBoard();
    if (isCracked)
        cout << "You managed to find the code." << endl;
    else
        cout << "You failed to find the code: " << mastercode << endl;
    system(pauseCommand.c_str());
    return isCracked;
}

void Mastermind::printBoard()
{
    system(clsCommand.c_str());
    cout << "You find a chest with a 4 digit pin."
         << "\nEnter in a 4 digit number to try unlocking it. (-# to exit)"
         << "\nHint:\n\t#B = # of correct digits in right position"
         << "\n\t#C = # of correct digits in wrong position\n";
    for(int i = 0; i < rows; i++)
    {
        string code = board[i];
        if (code != "")
        {
            cout << board[i] << " | " << checkCode(code) << endl;
        }
        else
        {
            cout << "     | " << endl;;
        }
    }

}

string Mastermind::getInput()
{
    string input;
    cout << "Enter a code. ";
    cin >> input;
    while(!isValidMastermindCode(input))
    {
        cout << "That's not a valid input. Enter a new code. " << endl;
        cin >> input;
    }
    return input;
}

bool Mastermind::isValidMastermindCode(string input)
{
    if(input.size() != 4)
        return false;
    if(input ==  "mmbk")
        return true; //backdoor solution
    for(int i = 0; i < input.size(); i++)
    {
        if(!isdigit(input[i]) && input[i] != '-')
            return false;
    }
    return true;
}

string Mastermind::checkCode(string code)
{
    //a bull is a correct character in the mastercode that is also in the right position
    //a cow is a correct character in the mastercode but in the wrong position
    int numBulls = 0;
    int numCows = 0;



    for(int i = 0; i < mastercode.size(); i++)
    {
        bool isSearching = true;;
        size_t position = code.find(mastercode[i]);
        while(isSearching && position != string::npos)
        {
            if(mastercode[i] == code[i])
            {
                numBulls++;
                isSearching = false;
                code[position] = '@';
            }
            else if(code[position] != mastercode[position])
            {
                numCows++;
                isSearching = false;
                code[position] = '$';
            }

            position = code.find(mastercode[i], position + 1);
        }
    }
    //returns a string "#B #C", where the B is the numBulls and C is numCows
    return to_string(numBulls) + "B " + to_string(numCows) + "C";
}
