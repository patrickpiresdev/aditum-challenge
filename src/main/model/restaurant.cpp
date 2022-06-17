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

bool Restaurant::opensLateNight() {
    return openingHour.compare(closingHour) > 0;
}

bool Restaurant::isOpeningHour(const Hour& hour) {
    return hour.equal(openingHour);
}

bool Restaurant::isClosingHour(const Hour& hour) {
    return hour.equal(closingHour);
}

bool Restaurant::isOpenAt(const Hour& hour) {
    if (opensLateNight()) {
        if (isOpeningHour(hour) || isClosingHour(hour))
            return true;
        return !hour.inRange(closingHour, openingHour);
    }

    return hour.inRange(openingHour, closingHour);
}
