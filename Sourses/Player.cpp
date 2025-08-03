#include "../headers/Player.h"

Player::Player() {
    health = 5;
}

int Player::get_health() {
    return health;
}

bool Player::is_die() {
    return get_health() < 1;
}

void Player::attack(int damage) {
    health -= damage;
    return;
}