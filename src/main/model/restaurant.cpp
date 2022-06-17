#include "restaurant.h"

Restaurant::Restaurant(std::string name, std::string openingHour, std::string closingHour):
    name(name),
    openingHour(openingHour),
    closingHour(closingHour) {}

Restaurant* Restaurant::from(const std::string& s) {
    std::string attributes[] = {"", "", ""};

    int p = 0;
    char delimiter = ',';
    for (char c : s) {
        if (c == '"') continue;
        if (c == delimiter) {
            p++;
            delimiter = '-';
            continue;
        }
        attributes[p] += c;
    }

    return new Restaurant(attributes[0], attributes[1], attributes[2]);
}

std::string Restaurant::getName() {
    return name;
}

std::string Restaurant::opensAt() {
    return openingHour;
}

std::string Restaurant::closesAt() {
    return closingHour;
}

int Restaurant::compare(const std::string& hour1, const std::string& hour2) {
    if (hour1.length() > hour2.length()) return 1;
    if (hour1.length() < hour2.length()) return -1;
    return hour1.compare(hour2);
}

bool Restaurant::inRange(const std::string& hour, const std::string& start, const std::string& end) {
    int liminf = compare(start, hour);
    int limsup = compare(end, hour);
    return liminf <= 0 && 0 <= limsup;
}

bool Restaurant::opensLateNight() {
    return compare(openingHour, closingHour) > 0;
}

bool Restaurant::equalHours(const std::string& hour1, const std::string& hour2) {
    return compare(hour1, hour2) == 0;
}

bool Restaurant::isOpeningHour(const std::string& hour) {
    return equalHours(hour, openingHour);
}

bool Restaurant::isClosingHour(const std::string& hour) {
    return equalHours(hour, closingHour);
}

bool Restaurant::isOpenAt(const std::string& hour) {
    if (this->opensLateNight()) {
        if (isOpeningHour(hour) || isClosingHour(hour))
            return true;
        return !inRange(hour, closingHour, openingHour);
    }

    return inRange(hour, openingHour, closingHour);
}
