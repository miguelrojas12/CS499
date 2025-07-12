#pragma once
#include <vector>
#include <string>

// Struct to hold time zone metadata
struct TimeZone {
    std::string name;
    int utc_offset;
    int dst_offset;
};

// Opens SQLite DB connection
bool openDatabase(const std::string& path);

// Closes active database
void closeDatabase();

// Loads all time zones from database
std::vector<TimeZone> loadTimeZones();