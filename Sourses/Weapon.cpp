#include "Weapon.h"
#include <random>

Weapon::Weapon() {}

bool Weapon::is_empty() {
    return ammo.empty();
}

std::string Weapon::gen_ammo() {
    setlocale(LC_ALL, "Russian");
    int quan = std::rand() % 5 + 4;
    live = std::rand() % (quan * 3 / 4) + (quan / 4);
    blank = quan - live;

    int remains_live = live;
    int remains_blank = blank;
    while (remains_live > 0 && remains_blank > 0) {
        if (std::rand() % 2 == 0) {
            --remains_live;
            ammo.push_back(true);
        } else {
            --remains_blank;
            ammo.push_back(false);
        }
    }

    for (; remains_live > 0; --remains_live) {
        ammo.push_back(true);
    }

    for (; remains_blank > 0; --remains_blank) {
        ammo.push_back(false);
    }

    return "Боевых: " + std::to_string(live) + "\tХолостых: " + std::to_string(blank) + "\n";
}

bool Weapon::shoot(Player& player) {
    bool result  = ammo.back();
    ammo.pop_back();
    if (result) {
        player.attack(1);
    }
    return result;
}