#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Arena.h"
using namespace std;
Character::Character(string n, int lvl, int hp, int atk, int def)
    : name(n), level(lvl), health(hp), attack(atk), defense(def) {
}
bool Character::isAlive() const {
    return health > 0;
}
string Character::getName() const {
    return name;
}
int Character::getHealth() const {
    return health;
}
void Character::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}
Character* operator+(const Character& a, const Character& b) {
    string newName = a.name + "_" + b.name;
    int newLevel = (a.level + b.level) / 2;
    int newHealth = a.health + b.health;
    int newAttack = a.attack + b.attack;
    int newDefense = a.defense + b.defense;

    return new Warrior(newName, newLevel, newHealth, newAttack, newDefense);
}
bool operator==(const Character& a, const Character& b) {
    return a.name == b.name;
}
ostream& operator<<(ostream& os, const Character& c) {
    os << "Name: " << c.name << ", Level: " << c.level
        << ", HP: " << c.health << ", ATK: " << c.attack
        << ", DEF: " << c.defense;
    return os;
}
