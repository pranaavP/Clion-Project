//
// Created by paladugup on 11/4/2025.
//

#ifndef BETTINGMETHOD_H
#define BETTINGMETHOD_H

#include <string>
#include <vector>

/*
 * BettingMethod
 * This class contains a collection of static functions that evaluate
 * different types of bets players can place in the Marble Racing Game.
 *
 * Each method compares the player's bet with the actual race results
 * and returns the number of coins the player wins for that bet type.
 *
 * All betting calculations are stateless and require only the provided
 * arguments, so the methods are static.
 */
class BettingMethod {
public:
    // Cost to place any type of bet
    static const int cost = 15;

    /*
     * 1. Predict the exact order of all 6 marbles.
     * Returns 500 coins if the bet order matches the exact race results.
     */
    static int exactOrder(const std::vector<std::string>& betOrder,
                          const std::vector<std::string>& actualOrder);

    /*
     * 2. Predict the winning marble.
     * Returns 50 coins if the chosen marble finishes 1st.
     */
    static int singleWinner(const std::string& betMarble,
                            const std::string& winner);

    /*
     * 3. Pick 2 marbles; if either wins the race, the player earns 25 coins.
     */
    static int twoMarbleWinner(const std::vector<std::string>& betMarbles,
                               const std::string& winner);

    /*
     * 4. Pick 3 marbles; if any of them wins the race, reward is 20 coins.
     */
    static int threeMarbleWinner(const std::vector<std::string>& betMarbles,
                                 const std::string& winner);

    /*
     * 5. Predict the exact 1st and 2nd place finishers.
     * Order must be correct to win 125 coins.
     */
    static int exactTopTwo(const std::vector<std::string>& betMarbles,
                           const std::vector<std::string>& actualOrder);

    /*
     * 6. Predict the top 2 finishers in any order.
     * Both predicted marbles must be in the top two positions (order doesn't matter)
     * to win 75 coins.
     */
    static int topTwoAnyOrder(const std::vector<std::string>& betMarbles,
                              const std::vector<std::string>& actualOrder);

    /*
     * 7. Predict which marbles finish in the top 3, in any order.
     * All three predicted marbles must appear in the top three positions
     * to win 100 coins.
     */
    static int topThreeAnyOrder(const std::vector<std::string>& betMarbles,
                                const std::vector<std::string>& actualOrder);

    /*
     * 8. Predict that two marbles finish next to each other.
     * The pair must appear consecutively anywhere in the results.
     * If true, return 200 coins.
     */
    static int adjacentMarbles(const std::vector<std::string>& betMarbles,
                               const std::vector<std::string>& actualOrder);
};

#endif
