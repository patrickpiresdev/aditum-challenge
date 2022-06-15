#include "restaurant.h"

Restaurant::Restaurant(std::string name, std::string openingHour, std::string closingHour):
    name(name),
    openingHour(openingHour),
    closingHour(closingHour) {}

std::string Restaurant::getName() {
    return name;
}

std::string Restaurant::opensAt() {
    return openingHour;
}

std::string Restaurant::closesAt() {
    return closingHour;
}

int compare(char c1, char c2) {
    return c1-c2;
}

int compare(std::string s1, std::string s2) {
    if (s1.length() > s2.length()) return 1;
    if (s1.length() < s2.length()) return -1;

    int compared;
    for (int i = 0; i < s1.length(); i++) {
        compared = compare(s1[i], s2[i]);
        if (compared > 0) return 1;
        if (compared < 0) return -1;
    }

    return 0;
}

bool inRange(std::string hour, std::string start, std::string end) {
    int liminf = compare(start, hour);
    int limsup = compare(end, hour);
    return liminf <= 0 && 0 <= limsup;
}

bool Restaurant::openedAtDawn() {
    return compare(openingHour, closingHour) > 0;
}

bool Restaurant::isOpenAt(std::string hour) {
    if (this->openedAtDawn())
        return !inRange(hour, closingHour, openingHour);
    return inRange(hour, openingHour, closingHour);
}

Restaurant* Restaurant::from(std::string s) {
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
