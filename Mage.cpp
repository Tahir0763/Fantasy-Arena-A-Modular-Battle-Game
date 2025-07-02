#include "Mage.h"
#include <iostream>
using namespace std;

Mage::Mage(string n)
    : Character(n, 1, 80, 40, 10) {
}

Mage::Mage(string n, int lvl, int hp, int atk, int def)
    : Character(n, lvl, hp, atk, def) {
}

void Mage::attackTarget(Character& target) {
    int damage = attack;
    cout << name << " casts Fireball at " << target.getName()
        << " for " << damage << " damage!\n";
    target.takeDamage(damage);
}

void Mage::useSpecialAbility() {
    cout << name << " channels arcane power to restore 20 HP!\n";
    health += 20;
}
