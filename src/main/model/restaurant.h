#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>

#include "hour.h"

class Restaurant {
    std::string name;
    Hour openingHour;
    Hour closingHour;

    bool opensLateNight();
    bool isOpeningHour(const Hour& hour);
    bool isClosingHour(const Hour& hour);

public:
    Restaurant(std::string name, std::string openingHour, std::string closingHour);
    static Restaurant* from(const std::string&);
    std::string getName();
    bool isOpenAt(const Hour& hour);
};

#endif // RESTAURANT_H
