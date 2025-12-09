//
// Created by paladugup on 11/4/2025.
//

#include "BettingMethod.h"
#include <algorithm>

/*
 * 1. Predict the exact finishing order of all 6 marbles.
 * If the player's predicted order matches the actual race result exactly,
 * they win a large reward (500 coins).
 */
int BettingMethod::exactOrder(const std::vector<std::string>& betOrder,
                              const std::vector<std::string>& actualOrder) {
    if (betOrder == actualOrder)
        return 500;
    return 0;
}

/*
 * 2. Predict the single winning marble.
 * If the player's marble wins the race, award 50 coins.
 */
int BettingMethod::singleWinner(const std::string& betMarble,
                                const std::string& winner) {
    return (betMarble == winner) ? 50 : 0;
}

/*
 * 3. Predict 1 out of 2 marbles to win.
 * If either of the two guessed marbles wins, award 25 coins.
 */
int BettingMethod::twoMarbleWinner(const std::vector<std::string>& betMarbles,
                                   const std::string& winner) {
    return (std::find(betMarbles.begin(), betMarbles.end(), winner) != betMarbles.end()) ? 25 : 0;
}

/*
 * 4. Predict 1 out of 3 marbles to win.
 * If the winning marble is one of the chosen three, award 20 coins.
 */
int BettingMethod::threeMarbleWinner(const std::vector<std::string>& betMarbles,
                                     const std::string& winner) {
    return (std::find(betMarbles.begin(), betMarbles.end(), winner) != betMarbles.end()) ? 20 : 0;
}

/*
 * 5. Predict the exact 1st and 2nd place finishers.
 * The order must match perfectly to earn 125 coins.
 */
int BettingMethod::exactTopTwo(const std::vector<std::string>& betMarbles,
                               const std::vector<std::string>& actualOrder) {
    if (betMarbles.size() == 2 && actualOrder.size() >= 2) {
        if (betMarbles[0] == actualOrder[0] && betMarbles[1] == actualOrder[1])
            return 125;
    }
    return 0;
}

/*
 * 6. Predict the top 2 finishers, but in any order.
 * Both predicted marbles must appear in the first two positions to win 75 coins.
 */
int BettingMethod::topTwoAnyOrder(const std::vector<std::string>& betMarbles,
                                  const std::vector<std::string>& actualOrder) {
    if (betMarbles.size() != 2 || actualOrder.size() < 2) return 0;

    std::vector<std::string> topTwo(actualOrder.begin(), actualOrder.begin() + 2);
    int count = 0;

    for (const auto& marble : betMarbles) {
        if (std::find(topTwo.begin(), topTwo.end(), marble) != topTwo.end())
            count++;
    }

    return (count == 2) ? 75 : 0;
}

/*
 * 7. Predict which marbles will finish in the top 3, in any order.
 * All three predicted marbles must appear in the top three positions to win 100 coins.
 */
int BettingMethod::topThreeAnyOrder(const std::vector<std::string>& betMarbles,
                                    const std::vector<std::string>& actualOrder) {
    if (betMarbles.size() != 3 || actualOrder.size() < 3) return 0;

    std::vector<std::string> topThree(actualOrder.begin(), actualOrder.begin() + 3);
    int count = 0;

    for (const auto& marble : betMarbles) {
        if (std::find(topThree.begin(), topThree.end(), marble) != topThree.end())
            count++;
    }

    return (count == 3) ? 100 : 0;
}

/*
 * 8. Predict that two specific marbles will finish next to each other.
 * Order does not matter; the pair must appear consecutively anywhere in the results.
 * This bet has a high reward (200 coins) because it is hard to predict.
 */
int BettingMethod::adjacentMarbles(const std::vector<std::string>& betMarbles,
                                   const std::vector<std::string>& actualOrder) {
    if (betMarbles.size() != 2) return 0;

    for (size_t i = 0; i < actualOrder.size() - 1; ++i) {
        bool forwardMatch = (actualOrder[i] == betMarbles[0] && actualOrder[i + 1] == betMarbles[1]);
        bool reverseMatch = (actualOrder[i] == betMarbles[1] && actualOrder[i + 1] == betMarbles[0]);

        if (forwardMatch || reverseMatch)
            return 200;
    }

    return 0;
}
