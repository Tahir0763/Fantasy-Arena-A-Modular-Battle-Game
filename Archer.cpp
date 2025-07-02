#include "Archer.h"
#include <iostream>
using namespace std;

Archer::Archer(string n)
    : Character(n, 1, 90, 25, 15) {
}

Archer::Archer(string n, int lvl, int hp, int atk, int def)
    : Character(n, lvl, hp, atk, def) {
}

void Archer::attackTarget(Character& target) {
    int damage = attack - (target.defense / 3);
    cout << name << " shoots an arrow at " << target.getName()
        << " for " << damage << " damage!\n";
    target.takeDamage(damage);
}

void Archer::useSpecialAbility() {
    cout << name << " uses Rapid Shot! Attack increased by 10!\n";
    attack += 10;
}
