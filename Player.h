//
// Created by paladugup on 11/4/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

/**
 * @class Player
 * @brief Represents a player in the Marble Racing Game.
 *
 * Each player has a name and a coin balance. The player can place bets,
 * receive rewards, and track their current coin total.
 */
class Player {
private:
    std::string name;  // Name of the player
    int coins;         // Current coin balance of the player

public:
    /**
     * @brief Constructs a Player with a given name and starting coins.
     * @param n Name of the player.
     * @param startingCoins Initial coin balance (default = 100).
     */
    Player(std::string n, int startingCoins = 100);

    /**
     * @brief Deducts the specified amount from the player's coins for a bet.
     * @param amount Coins to place as a bet.
     */
    void placeBet(int amount);

    /**
     * @brief Adds coins to the player's balance (e.g., after winning a bet).
     * @param amount Coins to add.
     */
    void addCoins(int amount);

    /**
     * @brief Displays the player's current coin balance.
     */
    void showCoins() const;

    /**
     * @brief Retrieves the player's name.
     * @return Player's name as a string.
     */
    std::string getName() const;

    /**
     * @brief Retrieves the player's current coin balance.
     * @return Number of coins the player has.
     */
    int getCoins() const;
};

#endif
