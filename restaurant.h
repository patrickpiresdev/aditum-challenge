#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>

class Restaurant {
    std::string name;
    std::string openingHour;
    std::string closingHour;

    bool openedAtDawn();
public:
    Restaurant(std::string name, std::string openingHour, std::string closingHour);
    std::string getName();
    std::string opensAt();
    std::string closesAt();
    bool isOpenAt(std::string hour);
    static Restaurant* from(std::string);
};

#endif // RESTAURANT_H
