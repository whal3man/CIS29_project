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
    cout << "\nGuess the single number password, between " << low << " and " << high << ".\n";
    int numToGuess = randInt(low, high);
    int numGuesses = 10;
    int guess;
    while(numGuesses >= 0)
    {
        cout << "\nYou have " << numGuesses << " guesses remaining. ";
        cin >> guess;
        if(guess == numToGuess)
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
    cout << "You ran out of guesses. Better luck next time!\n";
    system("pause");
    return false;
}
