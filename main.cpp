#include "MarbleRacingGame.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits> // for std::numeric_limits

int main() {
    srand(static_cast<unsigned>(time(0)));

    std::vector<std::string> marbleNames = {"Red", "Blue", "Green", "Yellow", "Purple", "Orange"};
    std::vector<std::string> playerNames;

    std::cout << "==============================\n";
    std::cout << "Welcome to the Marble Racing Game!\n";
    std::cout << "==============================\n";

    bool addingPlayers = true;
    while (addingPlayers) {
        std::string name;
        std::cout << "\nEnter player name: ";
        std::cin >> name;
        playerNames.push_back(name);

        int choice = 0;
        while (true) {
            std::cout << "\n1. Add another player\n";
            std::cout << "2. Begin the game\n";
            std::cout << "Choose an option: ";
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cin.clear(); // clear error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input! Please enter 1 or 2.\n";
                continue;
            }

            if (choice != 1 && choice != 2) {
                std::cout << "Invalid choice! Please enter 1 or 2.\n";
                continue;
            }
            break; // valid choice
        }

        if (choice == 2) {
            addingPlayers = false;
        }
    }

    if (playerNames.size() < 2) {
        std::cout << "\nAt least 2 players are required to start the game.\n";
        return 0;
    }

    MarbleRacingGame game(marbleNames, playerNames);
    game.placeBets();

    std::cout << "\nGame Over! Thanks for playing.\n";
    return 0;
}
