#include <iostream>
#include "GameManager.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Arena.h"
#include "Character.h"
#include <windows.h>
using namespace std;

Character* createCharacter(const string& playerLabel) {
    int choice;
    string name;
    cout << playerLabel << ", choose your character class:\n";
    cout << "1. Warrior\n2. Mage\n3. Archer\n> ";
    cin >> choice;
    cout << "Enter your character name: ";
    cin >> name;
    switch (choice) {
    case 1: return new Warrior(name);
    case 2: return new Mage(name);
    case 3: return new Archer(name);
    default:
        cout << "Invalid choice. Defaulting to Warrior.\n";
        return new Warrior(name);
    }
}
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int main() {
    setColor(2);
    GameManager gm;
   
    cout << "=== Fantasy Arena ===\n";

    Character* player1 = createCharacter("Player 1");
    Character* player2 = createCharacter("Player 2");
    
    string arenaName = "Dragon's Den";
    string arenaEffect = "fire";
    Arena* arena = new Arena(arenaName, arenaEffect, player1, player2);

    gm.setCharacters(player1, player2);
    gm.setArena(arena);

    gm.startGame();

    return 0;
}
