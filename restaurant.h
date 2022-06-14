#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>

class Restaurant {
    std::string name;
    std::string opensAt;
    std::string closesAt;
public:
    Restaurant(std::string name, std::string opensAt, std::string closesAt);
    std::string getName();
};

#endif // RESTAURANT_H
