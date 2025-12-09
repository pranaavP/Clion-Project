#ifndef MARBLE_H
#define MARBLE_H

#include <string>

/**
 * @class Marble
 * @brief Represents a marble participating in a race.
 *
 * Each marble has a name and a current position on the track.
 * The marble can move forward by a random amount influenced by a speed value.
 */
class Marble {
private:
    std::string name;  // Name of the marble
    int position;      // Current position in the race

public:
    /**
     * @brief Constructs a Marble object with a given name.
     * @param n The name of the marble.
     */
    Marble(const std::string& n);

    /**
     * @brief Moves the marble forward by a random amount scaled by the provided speed.
     * @param speed Maximum range of movement for this turn.
     */
    void moveRandom(int speed);

    /**
     * @brief Retrieves the marble's current position on the track.
     * @return Integer representing the marble’s position.
     */
    int getPosition() const;

    /**
     * @brief Retrieves the marble's name.
     * @return String of the marble’s name.
     */
    std::string getName() const;

    /**
     * @brief Resets the marble’s position back to the start of the race.
     */
    void resetPosition();
};

#endif
