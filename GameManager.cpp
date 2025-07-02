#include "GameManager.h"
#include <iostream>

GameManager::GameManager() : player1(nullptr), player2(nullptr), arena(nullptr) {}

GameManager::~GameManager() {
    delete player1;
    delete player2;
    delete arena;
}

void GameManager::setCharacters(Character* c1, Character* c2) {
    player1 = c1;
    player2 = c2;
}

void GameManager::setArena(Arena* a) {
    arena = a;
}

void GameManager::startGame() {
    if (arena) {
        arena->startBattle();
    }
    else {
        std::cout << "Arena not set!\n";
    }
}
