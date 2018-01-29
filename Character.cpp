#include "Character.h"
#include <iostream>

Character::Character()
{
    hp = 100;
    age = 0;
    name = "Undefined";
    strength = 5;
    perception = 5;
    endurance = 5;
    charisma = 5;
    age = 5;
    intelligence = 5;
    agility = 5;
    luck = 5;
    x = 0;
    y = 0;
    z = 9;
}

void Character::moveUp()
{
    y--;
}

void Character::moveDown()
{
    y++;
}

void Character::moveLeft()
{
    x--;
}

void Character::moveRight()
{
    x++;
}

int Character::getX()
{
    return x;
}

int Character::getY()
{
    return y;
}

int Character::getZ()
{
    return z;
}

int Character::getHP()
{
    return hp;
}

int Character::getAge()
{
    return age;
}

string Character::getName()
{
    return name;
}

int Character::getStrength()
{
    return strength;
}

int Character::getPerception()
{
    return perception;
}

int Character::getEndurance()
{
    return endurance;
}

int Character::getCharisma()
{
    return charisma;
}

int Character::getIntelligence()
{
    return intelligence;
}

int Character::getAgility()
{
    return agility;
}

int Character::getLuck()
{
    return luck;
}

void Character::setLoc(int x_, int y_)
{
    x = x_;
    y = y_;
}

void Character::setHP(int hp_)
{
    hp = hp_;
}

void Character::setAge(int age_)
{
    age = age_;
}

void Character::setName(string name_)
{
    name = name_;
}

void Character::setStrength(int strength_)
{
    strength = strength_;
}

void Character::setPerception(int perception_)
{
    perception = perception_;
}

void Character::setEndurance(int endurance_)
{
    endurance = endurance_;
}

void Character::setCharisma(int charisma_)
{
    charisma = charisma_;
}

void Character::setIntelligence(int intelligence_)
{
    intelligence = intelligence_;
}

void Character::setAgility(int agility_)
{
    agility = agility_;
}

void Character::setLuck(int luck_)
{
    luck = luck_;
}
