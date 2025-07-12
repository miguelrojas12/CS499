-- Recreate the TimeZones table with UTC and DST offsets
DROP TABLE IF EXISTS TimeZones;

CREATE TABLE TimeZones (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    zone_name TEXT NOT NULL,
    utc_offset INTEGER NOT NULL,
    dst_offset INTEGER NOT NULL
);

-- Insert standard global time zones
INSERT INTO TimeZones (zone_name, utc_offset, dst_offset) VALUES
    ('UTC', 0, 0),
    ('New York', -5, 1),
    ('Los Angeles', -8, 1),
    ('Chicago', -6, 1),
    ('London', 0, 1),
    ('Berlin', 1, 1),
    ('Tokyo', 9, 0),
    ('Sydney', 10, 1),
    ('Dubai', 4, 0),
    ('Johannesburg', 2, 0),
    ('New Delhi', 5, 0),
    ('Santiago', -4, 1),
    ('Toronto', -5, 1),
    ('Moscow', 3, 1),
    ('Rio de Janeiro', -3, 0),
    ('Singapore', 8, 0),
    ('Bangkok', 7, 0),
    ('Beijing', 8, 0),
    ('Honolulu', -10, 0),
    ('Anchorage', -9, 1);