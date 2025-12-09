//
// Created by paladugup on 11/4/2025.
//

#ifndef MARBLERACINGGAME_H
#define MARBLERACINGGAME_H

#include <vector>
#include <string>
#include "Marble.h"
#include "FinishLine.h"
#include "Player.h"
#include "BettingMethod.h"

/**
 * @class MarbleRacingGame
 * @brief Manages the full marble racing game including marbles, players,
 *        races, betting logic, and final results.
 *
 * This class coordinates:
 *  - Creating and storing marbles and players
 *  - Running animated marble races
 *  - Displaying betting options
 *  - Handling player turns, bets, and rewards
 *  - Triggering race results and game victory conditions
 */
class MarbleRacingGame {
private:
    std::vector<Marble> marbles;       // List of all marbles participating in races
    std::vector<Player> players;       // List of players placing bets
    FinishLine finishLine;             // Stores finishing order after each race

public:
    /**
     * @brief Constructor that initializes marbles and players.
     * @param marbleNames List of marble names to create.
     * @param playerNames List of player names to create.
     */
    MarbleRacingGame(std::vector<std::string> marbleNames, std::vector<std::string> playerNames);

    /**
     * @brief Runs a complete marble race from start to finish.
     *        Handles movement, animation, and final ranking generation.
     */
    void runRace();

    /**
     * @brief Displays all available betting methods, their costs, and rewards.
     */
    void displayBettingMethods();

    /**
     * @brief Main game loop handling player turns, bet selection,
     *        race executions, winnings, eliminations, and endgame logic.
     */
    void placeBets();
};

#endif // FINALPROJECT_MARBLERACINGGAME_H
