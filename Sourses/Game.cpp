#include "../headers/Game.h"
#include <iostream>

Game::Game() {
    player1 = Player();
    player2 = Player();
    turning = 1;
    weapon = Weapon();
};

void Game::move() {
    setlocale(LC_ALL, "Russian");

    if (weapon.is_empty()) {
        std::cout << weapon.gen_ammo();
    }

    std::cout 
        << "� ������ 1: " << player1.get_health() << " ������.\t" << "� ������ 2: " << player2.get_health() << " ������.\n"
        << "�������� � ������ " << turning << ".\n"
        << "� ���� ����������?\n"
        << "1 ��� 2?\n";

    int ans;
    std::cin >> ans;
    while (ans != 1 && ans != 2) {
        std::cin >> ans;
    }

    bool result;
    if (ans == 1) {
        result = weapon.shoot(player1);
    } else if (ans == 2) {
        result = weapon.shoot(player2);
    }

    if (player1.is_die()) {
        end(2);
    } else if (player2.is_die()) {
        end(1);
    } else {
        if (!(!result && ans == turning))
        turning = (turning + 1) % 3;
        move();
    }

    return;
};

void Game::end(int winner) {
    std::cout << "������� ����� " << winner << "!\n";
    return;
};