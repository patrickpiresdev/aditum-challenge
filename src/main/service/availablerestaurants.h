#ifndef AVAILABLERESTAURANTS_H
#define AVAILABLERESTAURANTS_H

#include <vector>
#include <string>

#include "../dao/restaurantdao.h"
#include "../model/restaurant.h"

class AvailableRestaurants {
    RestaurantDAO restaurantDao;
public:
    AvailableRestaurants(RestaurantDAO restaurantDao);
    std::vector<std::string> at(std::string hour);
};

#endif // AVAILABLERESTAURANTS_H
