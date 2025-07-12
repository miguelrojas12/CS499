#pragma once
#include "clock_engine.h"
#include "timezone_db.h"
#include <vector>

// Displays clock title/header
void showClockHeader();

// Displays formatted time
void displayTime(const Clock& clock, int format);

// Lists available time zones
void displayTimeZones(const std::vector<TimeZone>& zones);

// Displays main menu options
void displayMainMenu();