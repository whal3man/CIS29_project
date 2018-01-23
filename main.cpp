#include <iostream>
#include <string>
#include "include/Character.h"
#include "include/CharacterCreation.h"
using namespace std;

int main()
{
    cout << "Welcome to Escape the Vault.\n";
    cout << "You wake up, cold and confused. You start to remember who you are...\n";
    Character pchar;
    runCharacterCreation(pchar);
    string input = "";
    while(input != "quit") {
        cout << "Please enter a command.\n";
        cin >> input;
        for(int i = 0; i < input.size(); i++) {
            input[i] = tolower(input[i]);
        }
    }
}
