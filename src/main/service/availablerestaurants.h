#ifndef AVAILABLERESTAURANTS_H
#define AVAILABLERESTAURANTS_H

#include <vector>
#include <string>

#include "../dao/restaurantdao.h"
#include "../model/restaurant.h"
#include "../model/hour.h"

class AvailableRestaurants {
    RestaurantDAO restaurantDao;
public:
    AvailableRestaurants(RestaurantDAO restaurantDao);
    std::vector<std::string> at(const std::string& hourStr);
};

#endif // AVAILABLERESTAURANTS_H
