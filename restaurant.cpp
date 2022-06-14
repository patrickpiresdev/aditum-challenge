#include "restaurant.h"

#include <string>

Restaurant::Restaurant(std::string name, std::string opensAt, std::string closesAt):
    name(name),
    opensAt(opensAt),
    closesAt(closesAt) {}

std::string Restaurant::getName() {
    return name;
}
