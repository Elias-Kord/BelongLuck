#pragma once
#include "Player.h"
#include <vector>
#include <string>

class Weapon {
private:
    int live, blank;
    std::vector<bool> ammo = std::vector<bool>();

public:
    Weapon();

    bool is_empty();

    std::string gen_ammo();

    bool shoot(Player& player);
};