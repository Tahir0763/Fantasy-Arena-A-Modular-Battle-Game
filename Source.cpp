#include <iostream>
#include <string>
#include <cstdlib> // For rand()
using namespace std;
class Character;
class Arena;
class Mage;
class Character {
protected:
    string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int defense;

public:
    Character(string n, int lvl, int hp, int atk, int def)
        : name(n), level(lvl), health(hp), maxHealth(hp), attack(atk), defense(def) {
    }

    virtual ~Character() = default;
    virtual void attackTarget(Character& target) = 0;
    virtual void useSpecialAbility() = 0;

    // Getters
    string getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getLevel() const { return level; }

    // Setters
    void setHealth(int h) { health = (h > maxHealth) ? maxHealth : h; }
    void setMaxHealth(int mh) { maxHealth = mh; }
    void setAttack(int a) { attack = a; }
    void setDefense(int d) { defense = d; }

    // Operator Overloading
   

    bool operator==(const Character& other) {
        int thisPower = health + attack + defense;
        int otherPower = other.health + other.attack + other.defense;
        return thisPower == otherPower;
    }

    friend ostream& operator<<(ostream& os, const Character& c);
};
ostream& operator<<(ostream& os, const Character& c) {
    os << "[" << c.name << "] Lvl " << c.level
        << " | HP: " << c.health << "/" << c.maxHealth
        << " | ATK: " << c.attack << " | DEF: " << c.defense;
    return os;
}
class Warrior : public Character {
public:
    Warrior(std::string n, int lvl)
        : Character(n, lvl, 100 + lvl * 10, 15 + lvl * 2, 5 + lvl) {
    }

    // Safe + operator: returns a new Warrior with combined attack
    Warrior operator+(const Warrior& other) const {
        Warrior result = *this; // Copy this Warrior
        result.attack += other.attack;
        return result;
    }

    void attackTarget(Character& target) override {
        int damage = attack - (target.getDefense() / 2);
        if (damage < 0) damage = 0;
        target.setHealth(target.getHealth() - damage);
        std::cout << name << " slashes " << target.getName()
            << " for " << damage << " damage!\n";
    }

    void useSpecialAbility() override {
        attack += 15;
        health -= static_cast<int>(maxHealth * 0.05);
        std::cout << name << " enters BERSERK FURY! +15 ATK, but takes "
            << static_cast<int>(maxHealth * 0.05) << " recoil damage!\n";
    }
};


// Mage Class
class Mage : public Character {
public:
    Mage(std::string n, int lvl)
        : Character(n, lvl, 80 + lvl * 8, 8 + lvl, 3 + lvl) {
    }

    void attackTarget(Character& target) override {
        int damage = attack * 2; // Magic ignores defense
        target.setHealth(target.getHealth() - damage);
        std::cout << name << " casts a spell on " << target.getName()
            << " for " << damage << " damage!\n";
    }
    void useSpecialAbility() override {
        if (Arena::currentEnemy) {
            Character& enemy = *Arena::currentEnemy;
            int drainAmount = static_cast<int>(enemy.getHealth() * 0.2);
            health -= static_cast<int>(maxHealth * 0.05);

            // Ensure enemy stays alive
            if (enemy.getHealth() - drainAmount < 1) {
                drainAmount = enemy.getHealth() - 1;
            }

            // Apply effects
            enemy.setHealth(enemy.getHealth() - drainAmount);
            enemy.setMaxHealth(enemy.getMaxHealth() * 0.9);
            health = (health + drainAmount > maxHealth) ? maxHealth : health + drainAmount;

            cout << name << " steals " << drainAmount << " HP from "
                << enemy.getName() << "!\n";
            std::cout << enemy.getName() << "'s max HP reduced by 10%!\n";
        }
        else {
            std::cout << "No target for Soul Steal!\n";
        }
    }
};

// Arena Class (without vectors)
class Arena {
public:
    static Character* currentEnemy; // For targeting special abilities
    static const int MAX_FIGHTERS = 4;
    Arena(){}
    Arena(const string& name, const string& environment)
        : name(name), environment(environment), fighterCount(0) {
        for (int i = 0; i < MAX_FIGHTERS; i++) {
            fighters[i] = nullptr;
        }
    }

    void addFighter(Character* c) {
        if (fighterCount < MAX_FIGHTERS) {
            fighters[fighterCount++] = c;
            applyEnvironmentEffect(*c);
        }
    }

    void applyEnvironmentEffect(Character& c) {
        if (environment == "Fire") {
            c.setAttack(c.getAttack() + 5);
            c.setDefense(c.getDefense() - 3);
            cout << c.getName() << " gets +5 ATK/-3 DEF in Fire Arena\n";
        }
        else if (environment == "Ice") {
            c.setDefense(c.getDefense() + 5);
            c.setAttack(c.getAttack() - 2);
            cout << c.getName() << " gets +5 DEF/-2 ATK in Ice Arena\n";
        }
    }

    void runBattle() {
        while (fighterCount > 1) {
            for (int i = 0; i < fighterCount; i++) {
                if (!fighters[i] || fighters[i]->getHealth() <= 0) continue;

                // Set current enemy for special abilities
                currentEnemy = findRandomTarget(fighters[i]);

                if (rand() % 100 < 30) {
                    fighters[i]->useSpecialAbility();
                }
                else {
                    fighters[i]->attackTarget(*currentEnemy);
                }

                removeDeadFighters();
                if (fighterCount == 1) break;
            }
        }

        if (fighterCount == 1) {
            cout << fighters[0]->getName() << " wins in " << name << "!\n";
        }
    }
    string getName() const { return name; }
    string getEnvironment() const { return environment; }

private:
    string name;
    string environment;
    Character* fighters[MAX_FIGHTERS];
    int fighterCount;
    Character* findRandomTarget(Character* attacker) {
        Character* target = nullptr;
        do {
            int idx = rand() % fighterCount;
            target = fighters[idx];
        } while (target == attacker || !target || target->getHealth() <= 0);
        return target;
    }

    void removeDeadFighters() {
        for (int i = 0; i < fighterCount; i++) {
            if (fighters[i] && fighters[i]->getHealth() <= 0) {
                std::cout << fighters[i]->getName() << " has been defeated!\n";
                // Shift array
                for (int j = i; j < fighterCount - 1; j++) {
                    fighters[j] = fighters[j + 1];
                }
                fighters[--fighterCount] = nullptr;
                i--; // Re-check this index
            }
        }
    }
};

Character* Arena::currentEnemy = nullptr;

// Game Manager (without vectors)
class GameManager {
    static const int MAX_ARENAS = 3;
    static const int MAX_CHARS = 6;

    Arena arenas[MAX_ARENAS];
    Character* characters[MAX_CHARS];
    int arenaCount;
    int charCount;

public:
    GameManager() : arenaCount(0), charCount(0) {}

    void addArena(const Arena& a) {
        if (arenaCount < MAX_ARENAS) {
            arenas[arenaCount++] = a;
        }
    }

    void registerCharacter(Character* c) {
        if (charCount < MAX_CHARS) {
            characters[charCount++] = c;
        }
    }

    void startGame() {
        if (arenaCount == 0 || charCount < 2) {
            cerr << "Not enough arenas/characters!\n";
            return;
        }

        // Select random arena
        Arena& arena = arenas[rand() % arenaCount];
        cout << "Battle in " << arena.getName() << " ("
            << arena.getEnvironment() << ")\n";

        // Add 2 random fighters
        for (int i = 0; i < 2 && charCount > 0; i++) {
            int idx = rand() % charCount;
            arena.addFighter(characters[idx]);
            // Remove from available characters
            for (int j = idx; j < charCount - 1; j++) {
                characters[j] = characters[j + 1];
            }
            charCount--;
        }

        arena.runBattle();
    }

    // Additional utility functions would go here
};

int main() {
    // Create game elements
    Warrior w1("Conan", 5);
    Warrior w2("Hercules", 6);
    Mage m1("Merlin", 5);
    Mage m2("Gandalf", 7);

    Arena a1("Volcano", "Fire");
    Arena a2("Frostpeak", "Ice");

    GameManager game;
    game.addArena(a1);
    game.addArena(a2);

    game.registerCharacter(&w1);
    game.registerCharacter(&w2);
    game.registerCharacter(&m1);
    game.registerCharacter(&m2);

    // Demonstrate operator overloading
    Warrior combo = w1 + w2;
    cout << "Combo Attack Power: " << combo.getAttack() << "\n";

    cout << "Character Comparison:\n";
    cout << w1 << "\n" << w2 << "\n";
    cout << "Are they equal? " << (w1 == w2 ? "Yes" : "No") << "\n\n";

    // Start battle
    game.startGame();

    return 0;
}