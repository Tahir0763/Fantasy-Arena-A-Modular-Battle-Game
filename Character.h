#pragma once
#include <string>
#include <iostream>
using namespace std;
class Character {
public:
    string name;
    int level;
    int health;
    int attack;
    int defense;
    Character(string n, int lvl, int hp, int atk, int def);
    virtual ~Character() {}
    virtual void attackTarget(Character& target) = 0;
    virtual void useSpecialAbility() = 0;
    bool isAlive() const;
    string getName() const;
    int getHealth() const;
    void takeDamage(int amount);
    friend Character* operator+(const Character& a, const Character& b);
    friend bool operator==(const Character& a, const Character& b);
    friend ostream& operator<<(ostream& os, const Character& c);
    friend Character* createCharacter(const string& playerLabel);
};
