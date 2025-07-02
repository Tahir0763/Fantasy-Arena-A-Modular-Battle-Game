#pragma once
#include <string>
#include "Character.h"
using namespace std;

class Arena {
private:
    string name;
    string environmentalEffect;
    Character* player1;
    Character* player2;

public:
    Arena(string n, string effect, Character* p1, Character* p2);
    ~Arena();

    void startBattle();
};
