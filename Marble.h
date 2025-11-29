#ifndef MARBLE_H
#define MARBLE_H

#include <string>

class Marble {
private:
    std::string name;
    int position; // Current position in the race

public:
    Marble(const std::string& n);
    void moveRandom(int speed); // Move by given speed
    int getPosition() const;
    std::string getName() const;
    void resetPosition();
};

#endif
