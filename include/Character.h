#ifndef CHARACTER_H
#define CHARACTER_H

#include "../include/Inventory.h"
#include "../include/Item.h"
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

    void removeFromInventory(const Item& i)
    {
        inventory.remove(i);
    }
    void addToInventory(const Item i)
    {
        inventory.add(i);
    }
    void printInventory();
    bool hasItemsInInventory()
    {
        return inventory.containsItems();
    }
    int numItemsInInventory()
    {
        return inventory.getNumItems();
    }

    int takeDamage(int attack);
    int takeDamageFrom(Item& i, bool kill = false);
    int attack(Character& e, bool kill = false);

    void equip(int i);
    void unequip(int choice);
    Item& getEquippedWeapon()
    {
        return equippedWeapon;
    }
    Item& getEquippedArmor()
    {
        return equippedArmor;
    }

    Item defaultWeapon = Item("Fists");
    Item defaultArmor = Item("Pants");
    Item equippedWeapon = defaultWeapon;
    Item equippedArmor = defaultArmor;

    bool isAlive() const
    {
        return alive;
    }

    friend std::ostream& operator<<(ostream& os, const Character& c)
    {
        os << c.name << ", HP = " << c.hp;
        return os;
    }

    Inventory inventory;

    bool alive;

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

    int numEnemiesKilled() { return enemiesKilled; }
    int enemiesKilled;

    bool shouldOutput;
private:

};

#endif // CHARACTER_H
