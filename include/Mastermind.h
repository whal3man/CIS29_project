#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <string>

class Mastermind
{
private:
    std::string mastercode;
    int rows;
    std::string* board;

    void printBoard();
    std::string getInput();
    bool isValidMastermindCode(std::string input_);
    std::string checkCode(std:: string code_);

public:
    Mastermind() = default;
    Mastermind(std::string code_);
    Mastermind(int code_);
    ~Mastermind();
    Mastermind(int rows_, std::string code_);
    bool playGame();

};

#endif // MASTERMIND_H
