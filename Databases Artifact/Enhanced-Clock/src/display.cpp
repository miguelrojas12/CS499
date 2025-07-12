#include "display.h"
#include <iostream>

// Prints a formatted header for the live clock
void showClockHeader() {
    std::cout << "\n==============================\n";
    std::cout << "         Enhanced Clock        \n";
    std::cout << "==============================\n";
};

// Displays current time in chosen format
void displayTime(const Clock& clock, int format) {
    if (format == 12) {
        std::cout << "12-Hour Format: " << clock.format12() << "\n";
    } else {
        std::cout << "24-Hour Format: " << clock.format24() << "\n";
    }
}

// Lists all available time zones pulled from database
void displayTimeZones(const std::vector<TimeZone>& zones) {
    std::cout << "\nAvailable Time Zones:\n";
    for (size_t i = 0; i < zones.size(); ++i) {
        std::cout << i << ": " << zones[i].name
                  << " (UTC" << (zones[i].utc_offset >= 0 ? "+" : "")
                  << zones[i].utc_offset
                  << ", DST: " << zones[i].dst_offset << ")\n";
    }
};

// Displays the main menu options
void displayMainMenu() {
    std::cout << "\n-----------------------------\n";
    std::cout << "1. Enter start time\n";
    std::cout << "2. Select time zone\n";
    std::cout << "3. Choose format (12-hour or 24-hour)\n";
    std::cout << "4. Start clock\n";
    std::cout << "5. Exit\n";
    std::cout << "-----------------------------\n";
    std::cout << "Enter your choice: ";
};