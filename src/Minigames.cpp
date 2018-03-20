#include "../include/Minigames.h"
using namespace std;

bool guessingGame(int low, int high)
{
    system("cls");
    for(int i = 0; i < 3; i++)
    {
        cout << ". ";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "\nPassword entry software loaded.\n";
    cout << "Prepare to initiate password entry.\n";
    for(int i = 0; i < 3; i++)
    {
        cout << ". ";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "\nGuess the single positive number password, between " << low << " and " << high << ". (-# to exit)\n";
    int numToGuess = randInt(low, high);
    int numGuesses = 10;
    string guessStr;
    char guess;
    while(numGuesses > 0)
    {
        auto printNumGuesses = [=]()
        {
            cout << "\nYou have " << numGuesses << " guesses remaining. ";
        };
        printNumGuesses();
        cin >> guessStr;

        if(guessStr.size() == 1)
        {
            guess = guessStr[0];
            if(guess - 48 < 0) break;
            if(isdigit(guess))
            {
                if(guess - 48 == numToGuess)
                {
                    cout << "You got it, with " << numGuesses << " guesses remaining!\n";
                    system("pause");
                    return true;
                }
                else
                {
                    cout << "Try again.\n";
                    numGuesses--;
                }
            }
            else cout << "Error: invalid input. Please input a single number.\n";
        }
        else cout << "Error: invalid input. Please input a single number.\n";
    }
    cout << "You didn't guess the password: " << numToGuess << ". Better luck next time!\n";
    system("pause");
    return false;
}
