#include "Marble.h"

Marble::Marble(const std::string& n) : name(n), position(0) {}

void Marble::moveRandom(int speed) {
    position += speed; // Increment by speed provided by game loop
}

int Marble::getPosition() const { return position; }
std::string Marble::getName() const { return name; }
void Marble::resetPosition() { position = 0; }
