#include "MarbleRacingGame.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits> // For std::numeric_limits (input validation)

/*
 * Entry point for the Marble Racing Game.
 * Handles player input, validation, and game initialization.
 */
int main() {
    // Seed the random number generator for random race results
    srand(static_cast<unsigned>(time(0)));

    // Predefined marble names used in the race
    std::vector<std::string> marbleNames = {"Red", "Blue", "Green", "Yellow", "Purple", "Orange"};

    // List to store the names of players participating in the game
    std::vector<std::string> playerNames;

    std::cout << "==============================\n";
    std::cout << "Welcome to the Marble Racing Game!\n";
    std::cout << "==============================\n";

    bool addingPlayers = true;

    // Loop to collect player names until the user chooses to start the game
    while (addingPlayers) {
        std::string name;
        std::cout << "\nEnter player name: ";
        std::cin >> name;
        playerNames.push_back(name);

        int choice = 0;

        // Ask user whether to add another player or begin the game
        while (true) {
            std::cout << "\n1. Add another player\n";
            std::cout << "2. Begin the game\n";
            std::cout << "Choose an option: ";
            std::cin >> choice;

            // Validate input (non-integer or incorrect)
            if (std::cin.fail()) {
                std::cin.clear(); // Clear error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove bad input
                std::cout << "Invalid input! Please enter 1 or 2.\n";
                continue;
            }

            if (choice != 1 && choice != 2) {
                std::cout << "Invalid choice! Please enter 1 or 2.\n";
                continue;
            }

            break; // Input is valid
        }

        if (choice == 2) {
            addingPlayers = false;
        }
    }

    // Ensure the game only starts if there are at least 2 players
    if (playerNames.size() < 2) {
        std::cout << "\nAt least 2 players are required to start the game.\n";
        return 0;
    }

    // Create the game instance with marbles and players
    MarbleRacingGame game(marbleNames, playerNames);

    // Begin betting phase
    game.placeBets();

    std::cout << "\nGame Over! Thanks for playing.\n";
    return 0;
}
