#ifndef AVAILABLERESTAURANTS_H
#define AVAILABLERESTAURANTS_H

#include <vector>
#include <string>

#include "restaurantdao.h"
#include "restaurant.h"

class AvailableRestaurants {
    RestaurantDAO restaurantDao;
public:
    AvailableRestaurants(RestaurantDAO restaurantDao);
    std::vector<std::string> at(std::string hour);
};

#endif // AVAILABLERESTAURANTS_H
