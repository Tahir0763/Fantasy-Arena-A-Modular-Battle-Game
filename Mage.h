#pragma once
#include "Character.h"
using namespace std;

class Mage : public Character {
public:
    Mage(string name); 
    Mage(string name, int lvl, int hp, int atk, int def);  

    void attackTarget(Character& target);
    void useSpecialAbility();
};
