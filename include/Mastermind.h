#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <string>
using namespace std;

class Mastermind
{
private:
    string mastercode;
    int rows;
    string* board;

    void printBoard();
    string getInput();
    bool isValidMastermindCode(string input_);
    string checkCode( string code_);

public:
    Mastermind() = default;
    Mastermind(string code_);
    Mastermind(int code_);
    ~Mastermind();
    Mastermind(int rows_, string code_);
    bool playGame();

};

#endif // MASTERMIND_H
