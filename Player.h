//
// Created by paladugup on 11/4/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int coins;

public:
    Player(std::string n, int startingCoins = 100);

    void placeBet(int amount);
    void addCoins(int amount);
    void showCoins() const;
    std::string getName() const;
    int getCoins() const;
};

#endif
