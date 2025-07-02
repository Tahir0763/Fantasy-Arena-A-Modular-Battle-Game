#pragma once
#include "Arena.h"

class GameManager {
private:
    Character* player1;
    Character* player2;
    Arena* arena;

public:
    GameManager();
    ~GameManager();

    void setCharacters(Character* c1, Character* c2);
    void setArena(Arena* a);
    void startGame();
};
