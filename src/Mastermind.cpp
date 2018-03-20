#include "../include/Mastermind.h"
#include <iostream>

Mastermind::Mastermind(int code_) : rows(10)
{
    int missingZeroes = 0;
    if (code_ < 10)
        missingZeroes = 1;
    else if (code_ < 100)
        missingZeroes = 2;
    else if (code_ < 1000)
        missingZeroes = 3;
    mastercode = std::to_string(code_);
    while (missingZeroes > 0)
    {
        mastercode.insert(0, "0");
        missingZeroes--;
    }

    board = new std::string[rows];
}

Mastermind::Mastermind(std::string code_) : mastercode(code_), rows(10)
{
    board = new std::string[rows];
}

Mastermind::Mastermind(int rows_, std::string code_) : rows(rows_), mastercode(code_)
{
    board = new std::string[rows];
}

Mastermind::~Mastermind()
{
    delete[] board;
}

bool Mastermind::playGame()
{
    std::string input;
    bool isCracked = false;
    int currRound = 0;

    while(!isCracked && currRound < rows)
    {
//        std::cout << "The master code is " << mastercode << std::endl;
//        system("pause");
        printBoard();
        std::cout << "\nYou have " << rows - currRound << " guesses remaining." << std::endl;
        input = getInput();

        board[currRound] = input;
//        board[currRound][1] = checkCode(mastercode, input);
//        int numBulls = std::stoi(checkCode(input)[0]);

        if(input == "mmbk" || input == mastercode) isCracked = true;
        currRound++;
    }
    printBoard();
    if (isCracked)
        std::cout << "You managed to find the code." << std::endl;
    else
        std::cout << "You failed to find the code." << std::endl;
    system("pause");
    return isCracked;
}

void Mastermind::printBoard()
{
//    bool rowHasGuess;
    system("cls");
    std::cout << "You find a chest with a 4 digit pin."
              << "\nEnter in a 4 digit number to try unlocking it.\n";
    for(int i = 0; i < rows; i++)
    {
        std::string code = board[i];
        if (code != "")
        {
            std::cout << board[i] << " | " << checkCode(code) << std::endl;
        }
        else
        {
            std::cout << "     | " << std::endl;;
        }
    }

}

std::string Mastermind::getInput()
{
    std::string input;
    std::cout << "Enter a code. ";
    std::cin >> input;
    while(!isValidMastermindCode(input))
    {
        std::cout << "That's not a valid input. Enter a new code. " << std::endl;
        std::cin >> input;
    }
    return input;
}

bool Mastermind::isValidMastermindCode(std::string input)
{
    if(input.size() != 4) return false;
    if(input ==  "mmbk") return true; //backdoor solution
    for(int i = 0; i < input.size(); i++)
    {
        if(!isdigit(input[i])) return false;
    }
    return true;
}

std::string Mastermind::checkCode(std::string code)
{
    //a bull is a correct character in the mastercode that is also in the right position
    //a cow is a correct character in the mastercode but in the wrong position
    int numBulls = 0;
    int numCows = 0;



    for(int i = 0; i < mastercode.size(); i++)
    {
        bool isSearching = true;;
        size_t position = code.find(mastercode[i]);
        while(isSearching && position != std::string::npos)
        {
//            std::cout << "MC: " << mastercode << " C: " << code << std::endl;
            if(mastercode[i] == code[i])
            {
                numBulls++;
                isSearching = false;
                code[position] = '@';
            } else if(code[position] != mastercode[position])
            {
                numCows++;
                isSearching = false;
                code[position] = '$';
            }

            position = code.find(mastercode[i], position + 1);
        }
    }
    //returns a string "#B #C", where the B is the numBulls and C is numCows
    return std::to_string(numBulls) + "B " + std::to_string(numCows) + "C";
}
