#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "COIN.h"
#include <string>
using namespace std;

class Player : public Character
{
    public:
        Player() = default;
        Player(int startingX = 0, int startingY = 0, int startingZ = 9) : Character(startingX, startingY, startingZ) { shouldOutput = true; }

        void runCharacterCreation(const bool DEBUG);

        void displayInventory();

        void fillInventory();

        bool use(int idx);

        bool wonGame() { return (z < 0); }
        bool lostGame() { return !alive; }
        
        int getCap() const { return personal.getValue(); }
	    void setCap(int number) { personal.setValue(number); }
        
        friend std::ostream& operator<<(ostream& os, const Player& c)
        {
            os << c.name << ", HP = " << c.hp << ", Caps: " << c.inventory.getCaps() << ", Age = " << c.age << ", Enemies Killed = " << c.enemiesKilled
            << "\n You have " << c.getCap() << " caps right now!";
            
            return os;
        }
        
    private:
    Cap personal;
};

#endif // PLAYER_H
