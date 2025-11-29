#include "MarbleRacingGame.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <thread>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Constructor
MarbleRacingGame::MarbleRacingGame(std::vector<std::string> marbleNames, std::vector<std::string> playerNames) {
    for (auto& n : marbleNames) marbles.emplace_back(n);
    for (auto& n : playerNames) players.emplace_back(n);
}

void MarbleRacingGame::runRace() {
    const int trackLength = 60;

    if (marbles.size() != 6) {
        std::cerr << "Error: Race requires exactly 6 marbles.\n";
        return;
    }

    // Reset positions
    for (auto& m : marbles) m.resetPosition();

    FinishLine raceLine(trackLength);
    bool finished = false;

    // Seed RNG once
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }

    while (!finished) {
        finished = false;

        // Move each marble randomly 1-5 per tick
        for (auto& m : marbles) {
            int speed = 1 + std::rand() % 5;
            m.moveRandom(speed);

            if (m.getPosition() >= trackLength)
                finished = true; // race ends when any marble crosses finish line
        }

        // Always show exactly 6 rows
        raceLine.showRace(marbles);
    }

    // Record final results
    raceLine.recordResults(marbles);
    finishLine = raceLine; // store for betting

    // Print rankings
    auto results = finishLine.getResults();
    std::cout << "Race finished!\nRanking:\n";
    for (size_t i = 0; i < results.size(); ++i)
        std::cout << i + 1 << ". " << results[i] << "\n";
}

// Helper to display all betting methods
void MarbleRacingGame::displayBettingMethods() {
    std::cout << "\n------ Betting Methods ------\n";
    std::cout << "1. Predict exact order of all 6 marbles | Cost: 15 | Reward: 500\n";
    std::cout << "2. Choose 1 marble to win               | Cost: 15 | Reward: 50\n";
    std::cout << "3. Choose 2 marbles, whichever wins     | Cost: 15 | Reward: 25\n";
    std::cout << "4. Choose 3 marbles, any could win      | Cost: 15 | Reward: 20\n";
    std::cout << "5. Predict 1st and 2nd exact order      | Cost: 15 | Reward: 125\n";
    std::cout << "6. Pick 2 marbles top 2 any order       | Cost: 15 | Reward: 75\n";
    std::cout << "7. Choose 3 marbles top 3 any order     | Cost: 15 | Reward: 100\n";
    std::cout << "8. Predict 2 marbles next to each other | Cost: 15 | Reward: 200\n";
    std::cout << "9. All-in (use all 8 methods)           | Cost: 120 | Reward: sum of all successful bets\n";
    std::cout << "-------------------------------\n";
}

// Main betting loop
void MarbleRacingGame::placeBets() {
    std::cout << "\n==============================\n";
    std::cout << "     Marble Racing Game!   \n";
    std::cout << "==============================\n";

    bool gameOver = false;

    while (!gameOver && !players.empty()) {
        for (size_t i = 0; i < players.size(); ++i) {
            Player &player = players[i];
            if (player.getCoins() <= 0) continue;

            bool continueBetting = true;

            while (continueBetting) {
                std::cout << "\n" << player.getName() << ", it's your turn!\n";

                // Display all betting methods
                displayBettingMethods();

                int choice = 0;
                while (true) {
                    std::cout << "Enter your choice (1-9): ";
                    std::cin >> choice;
                    if (std::cin.fail() || choice < 1 || choice > 9) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input! Enter a number between 1 and 9.\n";
                        continue;
                    }
                    if (choice == 9 && player.getCoins() < 120) {
                        std::cout << "Not enough coins for All-in. Choose another option.\n";
                        continue;
                    } else if (choice != 9 && player.getCoins() < BettingMethod::cost) {
                        std::cout << "Not enough coins to place a bet. Ending turn.\n";
                        choice = 0;
                        break;
                    }
                    break;
                }

                if (choice == 0) break; // Not enough coins

                // Show available marbles
                std::cout << "\nAvailable marbles: ";
                for (auto& m : marbles) std::cout << m.getName() << " ";
                std::cout << "\n";

                auto getMarbleInput = [this](int count) -> std::vector<std::string> {
                    std::vector<std::string> inputs;
                    for (int j = 0; j < count; ++j) {
                        std::string name;
                        while (true) {
                            std::cin >> name;
                            // Validate marble exists
                            bool valid = false;
                            for (auto& m : marbles) {
                                if (m.getName() == name) {
                                    valid = true;
                                    break;
                                }
                            }
                            if (!valid) {
                                std::cout << "Invalid marble name! Enter again: ";
                                continue;
                            }
                            break;
                        }
                        inputs.push_back(name);
                    }
                    return inputs;
                };

                std::vector<std::string> betMarbles;
                std::vector<std::string> betOrder;

                switch (choice) {
                    case 1:
                        std::cout << "Enter exact order of all 6 marbles: ";
                        betOrder = getMarbleInput(6);
                        break;
                    case 2:
                        std::cout << "Enter 1 marble to win: ";
                        betMarbles = getMarbleInput(1);
                        break;
                    case 3:
                        std::cout << "Enter 2 marbles (space-separated): ";
                        betMarbles = getMarbleInput(2);
                        break;
                    case 4:
                        std::cout << "Enter 3 marbles (space-separated): ";
                        betMarbles = getMarbleInput(3);
                        break;
                    case 5:
                        std::cout << "Enter 1st and 2nd place exact order: ";
                        betMarbles = getMarbleInput(2);
                        break;
                    case 6:
                        std::cout << "Enter 2 marbles top 2 any order: ";
                        betMarbles = getMarbleInput(2);
                        break;
                    case 7:
                        std::cout << "Enter 3 marbles top 3 any order: ";
                        betMarbles = getMarbleInput(3);
                        break;
                    case 8:
                        std::cout << "Enter 2 marbles finishing next to each other: ";
                        betMarbles = getMarbleInput(2);
                        break;
                    case 9:
                        // All-in handled separately, can reuse getMarbleInput inside loop
                        break;
                }

                // Deduct bet
                if (choice == 9)
                    player.placeBet(120);
                else
                    player.placeBet(BettingMethod::cost);

                // Run race
                runRace();
                auto results = finishLine.getResults();
                std::string winner = results[0];
                int reward = 0;

                switch (choice) {
                    case 1: reward = BettingMethod::exactOrder(betOrder, results); break;
                    case 2: reward = BettingMethod::singleWinner(betMarbles[0], winner); break;
                    case 3: reward = BettingMethod::twoMarbleWinner(betMarbles, winner); break;
                    case 4: reward = BettingMethod::threeMarbleWinner(betMarbles, winner); break;
                    case 5: reward = BettingMethod::exactTopTwo(betMarbles, results); break;
                    case 6: reward = BettingMethod::topTwoAnyOrder(betMarbles, results); break;
                    case 7: reward = BettingMethod::topThreeAnyOrder(betMarbles, results); break;
                    case 8: reward = BettingMethod::adjacentMarbles(betMarbles, results); break;
                    case 9:
                        // All-in logic can be implemented separately with its own validation
                        break;
                }

                player.addCoins(reward);
                if (choice != 9)
                    std::cout << player.getName() << " won " << reward << " coins!\n";
                player.showCoins();

                // Check elimination or victory
                if (player.getCoins() <= 0) {
                    std::cout << player.getName() << " has been eliminated!\n";
                    players.erase(players.begin() + i);
                    --i;
                    break;
                }
                if (player.getCoins() > 150) {
                    std::cout << "\n " << player.getName() << " has reached over 150 coins and wins the game! \n";
                    gameOver = true;
                    break;
                }

                // Ask if player wants another bet (single bet only)
                if (choice != 9) {
                    int nextAction = 0;
                    while (true) {
                        std::cout << "\nDo you want to place another bet?\n1. Yes\n2. No, end turn\n";
                        std::cin >> nextAction;
                        if (std::cin.fail() || (nextAction != 1 && nextAction != 2)) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Invalid input! Enter 1 or 2.\n";
                            continue;
                        }
                        break;
                    }
                    if (nextAction != 1) continueBetting = false;
                } else {
                    continueBetting = false; // All-in ends turn automatically
                }

            } // end player's betting loop

            if (gameOver) break;
        } // end all players loop
    } // end game loop
}

