#pragma once
#include "Player.h"
#include "Weapon.h"

class Game {
private:
    Player player1, player2;

    int turning;

    Weapon weapon;

public:
    Game();

    void move();

    void end(int winner);
};