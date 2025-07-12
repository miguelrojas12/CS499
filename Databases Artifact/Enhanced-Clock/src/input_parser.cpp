#include "input_parser.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>

// Converts user input like "02:30:00 PM" or "14:00:00" into Clock object
Clock parseTimeInput(const std::string& input) {
    std::string timeStr = input;
    std::transform(timeStr.begin(), timeStr.end(), timeStr.begin(), ::toupper);

    // Detect suffix and sanitize string
    bool isPM = timeStr.find("PM") != std::string::npos;
    bool isAM = timeStr.find("AM") != std::string::npos;
    timeStr.erase(remove_if(timeStr.begin(), timeStr.end(), ::isalpha), timeStr.end());

    // Convert HH:MM:SS to integers
    std::replace(timeStr.begin(), timeStr.end(), ':', ' ');
    std::istringstream ss(timeStr);
    int h, m, s;
    ss >> h >> m >> s;

    // Apply AM/PM logic
    if (isPM && h < 12) h += 12;
    if (isAM && h == 12) h = 0;

    return Clock(h, m, s);
}