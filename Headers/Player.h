#pragma once

class Player {
private:
    int health;

public:
    Player();

    int get_health();

    bool is_die();

    void attack(int damage);
};