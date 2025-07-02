#include "Warrior.h"
#include <iostream>
using namespace std;
Warrior::Warrior(string n)
    : Character(n, 1, 120, 30, 20) {
}

Warrior::Warrior(std::string n, int lvl, int hp, int atk, int def)
    : Character(n, lvl, hp, atk, def) {
}

void Warrior::attackTarget(Character& target) {
    int damage = attack - (target.defense / 2);
    cout << name << " slashes " << target.getName() << " for " << damage << " damage!\n";
    target.takeDamage(damage);
}

void Warrior::useSpecialAbility() {
    cout << name << " enters Berserk mode! Attack doubled for one turn!\n";
    attack *= 2;
}
