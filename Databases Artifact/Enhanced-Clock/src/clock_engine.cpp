#include "clock_engine.h"
#include <iostream>
#include <thread>
#include <chrono>

// Initializes the clock with given hour, minute, and second
Clock::Clock(int h, int m, int s) : hour(h), minute(m), second(s) {}

// Increments time by one second and handles overflow
void Clock::tick() {
    second++;
    if (second >= 60) {
        second = 0;
        minute++;
    }
    if (minute >= 60) {
        minute = 0;
        hour++;
    }
    if (hour >= 24) {
        hour = 0;
    }
}

// Adds a UTC offset to the current hour and wraps around 24-hour format
void Clock::applyOffset(int offset) {
    hour = (hour + offset + 24) % 24;
}

// Formats the time in 12-hour format with AM/PM indicator
std::string Clock::format12() const {
    int displayHour = hour % 12;
    if (displayHour == 0) displayHour = 12;
    std::string period = hour >= 12 ? "PM" : "AM";

    char buffer[12];
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d %s", displayHour, minute, second, period.c_str());
    return std::string(buffer);
}

// Formats the time in 24-hour format
std::string Clock::format24() const {
    char buffer[9];
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hour, minute, second);
    return std::string(buffer);
}

// Starts the automatic time progression loop
void autoTimeLoop(Clock clock, int offset, int format) {
    while (true) {
        // Create a copy and apply time zone offset
        Clock adjusted = clock;
        adjusted.applyOffset(offset);

        // Display formatted time based on user’s format choice
        if (format == 12)
            std::cout << adjusted.format12() << "\n";
        else
            std::cout << adjusted.format24() << "\n";

        // Wait for one second before updating
        std::this_thread::sleep_for(std::chrono::seconds(1));
        clock.tick();

        // Future improvement: add user exit condition or pause option
    }
}