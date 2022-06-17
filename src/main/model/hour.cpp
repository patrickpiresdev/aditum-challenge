#include "hour.h"

Hour::Hour(const std::string& hour):
    hourValue(toInt(hour)) {}

int Hour::toInt(char c) {
    return c - 48;
}

int Hour::toInt(const std::string& hourStr) {
    int hour = 0;
    int s = hourStr.length()-2;

    for (char c : hourStr) {
        if (c == ':') continue;
        hour += toInt(c)*pow(10, s);
        s--;
    }

    return hour;
}

int Hour::value() const {
    return hourValue;
}

int Hour::compare(int another) const {
    return hourValue - another;
}

int Hour::compare(const Hour& another) const {
    return compare(another.value());
}

bool Hour::equal(const Hour& another) const {
    return compare(another) == 0;
}

bool Hour::inRange(const Hour& start, const Hour& end) const {
    return start.compare(hourValue) <= 0 && 0 <= end.compare(hourValue);
}
