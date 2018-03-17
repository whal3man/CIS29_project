#ifndef CHARACTER_H
#define CHARACTER_H

#include "../include/Inventory.h"
#include <string>
#include <iostream>
using namespace std;

class Character
{
public:
    Character(int startingX = 0, int startingY = 0, int startingZ = 9);
    ~Character() {}

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void goUpFloor();
    void goDownFloor();

    int getX();
    int getY();
    int getZ();
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

    void runCharacterCreation(const bool DEBUG);

    void use(string itemName);

    void removeFromInventory(const Item& i) { inventory.remove(i); }
    void addToInventory(const Item i) { inventory.add(i); }
    void printInventory();
    bool hasItemsInInventory() { return inventory.containsItems(); }
    int numItemsInInventory() { return inventory.getNumItems(); }

    void takeDamageFrom(Item& i);

    friend std::ostream& operator<<(ostream& os, const Character& c)
    {
        os << c.name << ", HP = " << c.hp << ", Age = " << c.age;
        return os;
    }

    Inventory inventory;

    int hp;
    int age;
    string name;

    int x;
    int y;
    int z;

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
