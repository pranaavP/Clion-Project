#include "Marble.h"

/*
 * Constructor
 * Initializes a marble with a name and sets its starting position to 0.
 */
Marble::Marble(const std::string& n) : name(n), position(0) {}

/*
 * moveRandom
 * Moves the marble forward by a given speed amount.
 * The speed is determined by the game loop (usually random).
 */
void Marble::moveRandom(int speed) {
    position += speed;  // Advance marble along the track
}

/*
 * getPosition
 * Returns the current position of the marble on the track.
 */
int Marble::getPosition() const {
    return position;
}

/*
 * getName
 * Returns the name of the marble.
 */
std::string Marble::getName() const {
    return name;
}

/*
 * resetPosition
 * Resets the marble back to the starting point (position 0).
 * Called before each new race.
 */
void Marble::resetPosition() {
    position = 0;
}
