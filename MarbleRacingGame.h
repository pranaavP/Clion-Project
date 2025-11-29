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

class MarbleRacingGame {
private:
    std::vector<Marble> marbles;
    std::vector<Player> players;
    FinishLine finishLine;

public:
    MarbleRacingGame(std::vector<std::string> marbleNames, std::vector<std::string> playerNames);

    void runRace();

    void displayBettingMethods();

    void placeBets();
};

#endif //FINALPROJECT_MARBLERACINGGAME_H