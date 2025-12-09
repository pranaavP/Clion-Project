#include "FinishLine.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

/*
 * Constructor
 * Stores the track length for the race animation.
 */
FinishLine::FinishLine(int length) : trackLength(length) {}

/*
 * showRace
 * Displays the current positions of all marbles on the track.
 *
 * Each marble is shown as:
 *     [spaces] o [spaces] |
 * where:
 *   - 'o' is the marble
 *   - '|' represents the finish line
 *
 * The function prints all 6 marbles vertically and refreshes every frame.
 */
void FinishLine::showRace(const std::vector<Marble>& marbles) {
    // Ensure exactly 6 marbles are provided to maintain race structure
    if (marbles.size() != 6) {
        std::cerr << "Error: Race must have exactly 6 marbles!\n";
        return;
    }

    // Move cursor to the beginning (lightweight way to refresh output)
    std::cout << "\r";

    // Display each marble's position
    for (int i = 0; i < 6; ++i) {
        const auto& m = marbles[i];
        int pos = m.getPosition();       // current location of marble
        if (pos > trackLength) pos = trackLength;

        // Print spaces up to marble's position
        for (int j = 0; j < pos; ++j)
            std::cout << " ";

        std::cout << "o"; // the marble icon

        // Print remaining spaces until the finish line
        for (int j = pos + 1; j <= trackLength; ++j)
            std::cout << " ";

        std::cout << "|\n"; // finish line marker
    }

    std::cout << std::endl;

    // Delay to create animation effect
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

/*
 * recordResults
 * Sorts marbles by their final position (largest = closest to finish line)
 * and saves their names into the 'results' vector.
 */
void FinishLine::recordResults(const std::vector<Marble>& marbles) {
    results.clear();
    std::vector<Marble> temp = marbles;

    // Sort marbles by descending position
    std::sort(temp.begin(), temp.end(), [](const Marble& a, const Marble& b) {
        return a.getPosition() > b.getPosition();
    });

    // Store finishing order by name
    for (auto& m : temp)
        results.push_back(m.getName());
}

/*
 * getResults
 * Returns the finishing order of the marbles as a vector of names.
 */
std::vector<std::string> FinishLine::getResults() const {
    return results;
}

/*
 * clear
 * Clears the stored race results so a new race can begin.
 */
void FinishLine::clear() {
    results.clear();
}
