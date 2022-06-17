#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>

class Restaurant {
    std::string name;
    std::string openingHour;
    std::string closingHour;

    int compare(const std::string& hour1, const std::string& hour2);
    bool inRange(const std::string& hour, const std::string& start, const std::string& end);
    bool opensLateNight();
    bool equalHours(const std::string& hour1, const std::string& hour2);
    bool isOpeningHour(const std::string& hour);
    bool isClosingHour(const std::string& hour);

public:
    Restaurant(std::string name, std::string openingHour, std::string closingHour);
    static Restaurant* from(const std::string&);
    std::string getName();
    std::string opensAt();
    std::string closesAt();
    bool isOpenAt(const std::string& hour);
};

#endif // RESTAURANT_H
