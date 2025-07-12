#include "timezone_db.h"
#include <sqlite3.h>
#include <iostream>

// Global pointer to the database connection
sqlite3* db = nullptr;

/**
 * Opens the SQLite database located at the given path.
 * Returns true on success, false on failure.
 */
bool openDatabase(const std::string& path) {
    int rc = sqlite3_open(path.c_str(), &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << "\n";
        return false;
    }
    return true;
}

/**
 * Closes the active SQLite database connection.
 */
void closeDatabase() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

/**
 * SQLite callback function to convert query results into TimeZone structs.
 * Called once per row returned from the SELECT statement.
 */
static int zoneCallback(void* data, int argc, char** argv, char** colNames) {
    auto* zones = static_cast<std::vector<TimeZone>*>(data);
    if (argc >= 3) {
        TimeZone tz;
        tz.name = argv[0] ? argv[0] : "Unknown";
        tz.utc_offset = argv[1] ? std::stoi(argv[1]) : 0;
        tz.dst_offset = argv[2] ? std::stoi(argv[2]) : 0;
        zones->push_back(tz);
    }
    return 0;
}

/**
 * Loads all time zones from the TimeZones table.
 * Returns a vector of TimeZone structs.
 */
std::vector<TimeZone> loadTimeZones() {
    std::vector<TimeZone> results;
    const char* query = "SELECT zone_name, utc_offset, dst_offset FROM TimeZones;";

    int rc = sqlite3_exec(db, query, zoneCallback, &results, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error querying time zones: " << sqlite3_errmsg(db) << "\n";
    }

    return results;
}