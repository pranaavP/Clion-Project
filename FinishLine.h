#ifndef FINISHLINE_H
#define FINISHLINE_H

#include <vector>
#include <string>
#include "Marble.h"

/*
 * FinishLine
 * This class manages everything related to displaying the race visually
 * and determining the final results of the Marble Racing Game.
 *
 * Responsibilities:
 *   • Animate the race by printing marble positions frame-by-frame.
 *   • Determine finishing order once the race ends.
 *   • Store and provide access to race results.
 *   • Reset results for the next race.
 */
class FinishLine {
private:
    int trackLength;                    // Total length of the race track (characters)
    std::vector<std::string> results;   // Names of marbles in finishing order

public:
    /*
     * Constructor
     * Creates a FinishLine object with the specified track length.
     * Default length = 60 characters.
     */
    FinishLine(int length = 60);

    /*
     * showRace
     * Displays the current race state in the console.
     * Each marble is printed at its corresponding position along the track.
     * The output animates by refreshing every frame.
     */
    void showRace(const std::vector<Marble>& marbles);

    /*
     * recordResults
     * Sorts the marbles based on their final position and stores their names
     * in 'results' from 1st place to last.
     */
    void recordResults(const std::vector<Marble>& marbles);

    /*
     * getResults
     * Returns a vector of marble names in the order they finished the race.
     */
    std::vector<std::string> getResults() const;

    /*
     * clear
     * Clears stored results so a new race can begin.
     */
    void clear();
};

#endif
