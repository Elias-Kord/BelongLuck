#include "Player.h"
#include <vector>
#include <string>

#ifndef Weapon_h
#define Weapon_h

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

#endif