//
// Created by paladugup on 11/4/2025.
//

#include "BettingMethod.h"
#include <algorithm>

// 1. Predict exact order of all 6 marbles
int BettingMethod::exactOrder(const std::vector<std::string>& betOrder,
                              const std::vector<std::string>& actualOrder) {
    if (betOrder == actualOrder)
        return 500;
    return 0;
}

// 2. Choose 1 marble to win
int BettingMethod::singleWinner(const std::string& betMarble,
                                const std::string& winner) {
    return (betMarble == winner) ? 50 : 0;
}

// 3. Choose 2 marbles; whichever wins
int BettingMethod::twoMarbleWinner(const std::vector<std::string>& betMarbles,
                                   const std::string& winner) {
    return (std::find(betMarbles.begin(), betMarbles.end(), winner) != betMarbles.end()) ? 25 : 0;
}

// 4. Choose 3 marbles; any could win
int BettingMethod::threeMarbleWinner(const std::vector<std::string>& betMarbles,
                                     const std::string& winner) {
    return (std::find(betMarbles.begin(), betMarbles.end(), winner) != betMarbles.end()) ? 20 : 0;
}

// 5. Predict 1st and 2nd in exact order
int BettingMethod::exactTopTwo(const std::vector<std::string>& betMarbles,
                               const std::vector<std::string>& actualOrder) {
    if (betMarbles.size() == 2 && actualOrder.size() >= 2) {
        if (betMarbles[0] == actualOrder[0] && betMarbles[1] == actualOrder[1])
            return 125;
    }
    return 0;
}

// 6. Pick 2 marbles to finish 1st and 2nd in any order
int BettingMethod::topTwoAnyOrder(const std::vector<std::string>& betMarbles,
                                  const std::vector<std::string>& actualOrder) {
    if (betMarbles.size() != 2 || actualOrder.size() < 2) return 0;
    std::vector<std::string> topTwo(actualOrder.begin(), actualOrder.begin() + 2);
    int count = 0;
    for (const auto& marble : betMarbles) {
        if (std::find(topTwo.begin(), topTwo.end(), marble) != topTwo.end()) count++;
    }
    return (count == 2) ? 75 : 0;
}

// 7. Choose 3 marbles that finish in the top 3 (any order)
int BettingMethod::topThreeAnyOrder(const std::vector<std::string>& betMarbles,
                                    const std::vector<std::string>& actualOrder) {
    if (betMarbles.size() != 3 || actualOrder.size() < 3) return 0;
    std::vector<std::string> topThree(actualOrder.begin(), actualOrder.begin() + 3);
    int count = 0;
    for (const auto& marble : betMarbles) {
        if (std::find(topThree.begin(), topThree.end(), marble) != topThree.end()) count++;
    }
    return (count == 3) ? 100 : 0;
}

// 8. Predict two specific marbles will finish next to each other
int BettingMethod::adjacentMarbles(const std::vector<std::string>& betMarbles,
                                   const std::vector<std::string>& actualOrder) {
    if (betMarbles.size() != 2) return 0;
    for (size_t i = 0; i < actualOrder.size() - 1; ++i) {
        if ((actualOrder[i] == betMarbles[0] && actualOrder[i + 1] == betMarbles[1]) ||
            (actualOrder[i] == betMarbles[1] && actualOrder[i + 1] == betMarbles[0])) {
            return 200;
        }
    }
    return 0;
}
