#ifndef FINISHLINE_H
#define FINISHLINE_H

#include <vector>
#include <string>
#include "Marble.h"

class FinishLine {
private:
    int trackLength;
    std::vector<std::string> results; // store marble names in finishing order

public:
    FinishLine(int length = 60);
    void showRace(const std::vector<Marble>& marbles);
    void recordResults(const std::vector<Marble>& marbles);
    std::vector<std::string> getResults() const;
    void clear();
};

#endif
