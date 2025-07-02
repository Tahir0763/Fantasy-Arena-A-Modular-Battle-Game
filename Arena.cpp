#include "Arena.h"
#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std;

Arena::Arena(string n, string effect, Character* p1, Character* p2)
    : name(n), environmentalEffect(effect), player1(p1), player2(p2) {
}

Arena::~Arena() {}

void Arena::startBattle() {
    ofstream logFile("battle_report.txt");  
    cout << "=== Welcome to " << name << " Arena! ===\n";
    cout << "Environment Effect: " << environmentalEffect << "\n\n";
    logFile << "=== Welcome to " << name << " Arena! ===\n";
    logFile << "Environment Effect: " << environmentalEffect << "\n\n";
    int turn = 1;

    while (player1->isAlive() && player2->isAlive()) {
        logFile << "---- Turn " << turn << " ----\n";
        cout << "---- Turn " << turn << " ----\n";
        if (turn % 2 == 1) {
            cout << player1->getName() << "'s turn:\n";
            logFile << player1->getName() << "'s turn:\n";

            player1->attackTarget(*player2);
            logFile << player1->getName() << " attacked " << player2->getName() << "\n";

            player1->useSpecialAbility();
            logFile << player1->getName() << " used their special ability\n";
        }
        else {
          
            cout << player2->getName() << "'s turn:\n";
            
            logFile << player2->getName() << "'s turn:\n";

            player2->attackTarget(*player1);
            logFile << player2->getName() << " attacked " << player1->getName() << "\n";

            player2->useSpecialAbility();
            logFile << player2->getName() << " used their special ability\n";
        }

        logFile << player1->getName() << " HP: " << player1->getHealth() << "\n";
        logFile << player2->getName() << " HP: " << player2->getHealth() << "\n\n";

        ++turn;
    }

    string winner = player1->isAlive() ? player1->getName() : player2->getName();
   
    cout << winner << " wins the battle!\n";
   
    logFile << winner << " wins the battle!\n";

    logFile.close();
}
