//
// Created by paladugup on 11/4/2025.
//

#ifndef BETTINGMETHOD_H
#define BETTINGMETHOD_H

#include <string>
#include <vector>

class BettingMethod {
public:
    static const int cost = 15;

    // 1. Predict exact order of all 6 marbles
    static int exactOrder(const std::vector<std::string>& betOrder,
                          const std::vector<std::string>& actualOrder);

    // 2. Choose 1 marble to win
    static int singleWinner(const std::string& betMarble,
                            const std::string& winner);

    // 3. Choose 2 marbles; whichever wins
    static int twoMarbleWinner(const std::vector<std::string>& betMarbles,
                               const std::string& winner);

    // 4. Choose 3 marbles; any could win
    static int threeMarbleWinner(const std::vector<std::string>& betMarbles,
                                 const std::string& winner);

    // 5. Predict 1st and 2nd in exact order
    static int exactTopTwo(const std::vector<std::string>& betMarbles,
                           const std::vector<std::string>& actualOrder);

    // 6. Pick 2 marbles to finish 1st and 2nd in any order
    static int topTwoAnyOrder(const std::vector<std::string>& betMarbles,
                              const std::vector<std::string>& actualOrder);

    // 7. Choose 3 marbles that finish in the top 3 (any order)
    static int topThreeAnyOrder(const std::vector<std::string>& betMarbles,
                                const std::vector<std::string>& actualOrder);

    // 8. Predict two specific marbles will finish next to each other
    static int adjacentMarbles(const std::vector<std::string>& betMarbles,
                               const std::vector<std::string>& actualOrder);
};

#endif

