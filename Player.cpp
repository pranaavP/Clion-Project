//
// Created by paladugup on 11/4/2025.
//

#include "Player.h"
#include <iostream>

Player::Player(std::string n, int startingCoins) : name(n), coins(startingCoins) {}

void Player::placeBet(int amount) {
    if (coins >= amount)
        coins -= amount;
    else
        std::cout << name << " does not have enough coins!\n";
}

void Player::addCoins(int amount) {
    coins += amount;
}

void Player::showCoins() const {
    std::cout << name << " has " << coins << " coins.\n";
}

std::string Player::getName() const {
    return name;
}

int Player::getCoins() const {
    return coins;
}
