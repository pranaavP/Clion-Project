#include "FinishLine.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

FinishLine::FinishLine(int length) : trackLength(length) {}

void FinishLine::showRace(const std::vector<Marble>& marbles) {
    // Ensure exactly 6 marbles
    if (marbles.size() != 6) {
        std::cerr << "Error: Race must have exactly 6 marbles!\n";
        return;
    }

    // Cross-platform clear
    std::cout << "\r"; // return to beginning of the line

    for (int i = 0; i < 6; ++i) {
        const auto& m = marbles[i];
        int pos = m.getPosition();
        if (pos > trackLength) pos = trackLength;

        // Print spaces before marble
        for (int j = 0; j < pos; ++j) std::cout << " ";
        std::cout << "o"; // marble

        // Print spaces to finish line
        for (int j = pos + 1; j <= trackLength; ++j) std::cout << " ";
        std::cout << "|\n";
    }

    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // frame delay
}

void FinishLine::recordResults(const std::vector<Marble>& marbles) {
    results.clear();
    std::vector<Marble> temp = marbles;

    // Sort by position descending
    std::sort(temp.begin(), temp.end(), [](const Marble& a, const Marble& b) {
        return a.getPosition() > b.getPosition();
    });

    for (auto& m : temp) results.push_back(m.getName());
}

std::vector<std::string> FinishLine::getResults() const {
    return results;
}

void FinishLine::clear() {
    results.clear();
}
