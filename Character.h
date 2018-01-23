#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character
{
    public:
        Character();

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

        int getX();
        int getY();
        int getHP();
        int getAge();
        string getName();
        int getStrength();
        int getPerception();
        int getEndurance();
        int getCharisma();
        int getIntelligence();
        int getAgility();
        int getLuck();

        void setLoc(int x, int y);
        void setHP(int hp);
        void setAge(int age);
        void setName(string name);
        void setStrength(int strength);
        void setPerception(int perception);
        void setEndurance(int endurance);
        void setCharisma(int charisma);
        void setIntelligence(int intelligence);
        void setAgility(int agility);
        void setLuck(int luck);

    protected:
        int hp;
        int age;
        string name;

        int x;
        int y;

        int strength;
        int perception;
        int endurance;
        int charisma;
        int intelligence;
        int agility;
        int luck;
    private:

};

#endif // CHARACTER_H
