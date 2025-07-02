#pragma once
#include "Character.h"
using namespace std;
class Warrior : public Character {
public:
    Warrior(string name); 
    Warrior(string name, int lvl, int hp, int atk, int def);

    void attackTarget(Character& target) ;
    void useSpecialAbility();
};
