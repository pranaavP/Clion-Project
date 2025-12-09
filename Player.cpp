//
// Created by paladugup on 11/4/2025.
//
// Player class implementation: Handles player identity,
// coin balance management, and basic betting actions.
//

#include "Player.h"
#include <iostream>

/**
 * @brief Constructs a Player object with a given name and starting coin balance.
 * @param n Name of the player.
 * @param startingCoins Initial number of coins the player begins with.
 */
Player::Player(std::string n, int startingCoins) : name(n), coins(startingCoins) {}

/**
 * @brief Deducts the bet amount from the player's coins.
 *
 * If the player does not have enough coins, the method prints a warning
 * and does not change the coin balance.
 *
 * @param amount Amount of coins to deduct for a bet.
 */
void Player::placeBet(int amount) {
    if (coins >= amount)
        coins -= amount;
    else
        std::cout << name << " does not have enough coins!\n";
}

/**
 * @brief Adds a specified number of coins to the player's balance.
 * @param amount Coins earned from winning a bet.
 */
void Player::addCoins(int amount) {
    coins += amount;
}

/**
 * @brief Displays the player's current coin balance to the console.
 */
void Player::showCoins() const {
    std::cout << name << " has " << coins << " coins.\n";
}

/**
 * @brief Retrieves the player's name.
 * @return Player's name as a string.
 */
std::string Player::getName() const {
    return name;
}

/**
 * @brief Retrieves the player's current coin total.
 * @return Number of coins the player has.
 */
int Player::getCoins() const {
    return coins;
}
