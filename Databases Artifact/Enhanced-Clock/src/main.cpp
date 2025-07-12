#include <iostream>
#include "clock_engine.h"
#include "input_parser.h"
#include "timezone_db.h"
#include "display.h"

// Main function and entry point of the program
int main() {
    // Step 1: This is where the user opens the SQLite database
    if (!openDatabase("database/timezones.db")) {
        std::cerr << "Error opening database.\n";
        return 1;
    }

    // Step 2: Load all available time zones from database
    std::vector<TimeZone> zones = loadTimeZones();

    Clock clock;                      // Clock instance to track current time
    TimeZone selectedZone;           // User-selected time zone
    int formatChoice = 24;           // Display format (12 or 24 hour)
    bool running = true;

    // Step 3: Main menu loop
    while (running) {
        std::cout << "\nChoose an option:\n"
                  << "1. Enter start time\n"
                  << "2. Select time zone\n"
                  << "3. Choose format (12/24)\n"
                  << "4. Start clock\n"
                  << "5. Exit\n> ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string input;
                std::cout << "Enter time (HH:MM:SS AM/PM or 24hr): ";
                std::cin.ignore(); // Clear newline
                std::getline(std::cin, input); // Capture full line
                clock = parseTimeInput(input); // Convert to Clock object
                break;
            }
            case 2: {
                displayTimeZones(zones); // Show available zones
                int zoneId;
                std::cout << "Select time zone index: ";
                std::cin >> zoneId;
                if (zoneId >= 0 && zoneId < zones.size())
                    selectedZone = zones[zoneId]; // Store selection
                break;
            }
            case 3: {
                std::cout << "Enter format (12 or 24): ";
                std::cin >> formatChoice;
                break;
            }
            case 4:
                // Launch real-time ticking clock
                autoTimeLoop(clock, selectedZone.utc_offset + selectedZone.dst_offset, formatChoice);
                break;
            case 5:
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    }

    // Step 4: Clean up database connection
    closeDatabase();
    return 0;
}