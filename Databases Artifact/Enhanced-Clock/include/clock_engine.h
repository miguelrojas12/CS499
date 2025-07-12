#pragma once

#include <string>

// Defines the Clock class that manages internal time state
class Clock {
public:
    int hour;    // Stores hour in 24-hour format
    int minute;  // Stores minutes (0–59)
    int second;  // Stores seconds (0–59)

    // Constructor with default initialization
    Clock(int h = 0, int m = 0, int s = 0);

    // Advances the clock by one second
    void tick();

    // Applies a UTC offset, including DST, to adjust the hour
    void applyOffset(int offset);

    // Converts current time to a 12-hour string with AM/PM
    std::string format12() const;

    // Converts current time to a standard 24-hour string
    std::string format24() const;
};

// Launches the real-time progression loop
void autoTimeLoop(Clock clock, int offset, int format);