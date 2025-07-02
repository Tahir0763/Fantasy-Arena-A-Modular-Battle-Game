#pragma once
#include "Character.h"
using namespace std;
class Archer : public Character {
public:
    Archer(string name);
    Archer(string name, int lvl, int hp, int atk, int def);

    void attackTarget(Character& target);
    void useSpecialAbility();
};
