#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>

class Restaurant {
    std::string name;
    std::string openingHour;
    std::string closingHour;

    bool opensLateNight();
    bool isOpeningHour(std::string hour);
    bool isClosingHour(std::string hour);

public:
    Restaurant(std::string name, std::string openingHour, std::string closingHour);
    std::string getName();
    std::string opensAt();
    std::string closesAt();
    bool isOpenAt(std::string hour);
    static Restaurant* from(std::string);
};

#endif // RESTAURANT_H
