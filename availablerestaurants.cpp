#include "availablerestaurants.h"

AvailableRestaurants::AvailableRestaurants(RestaurantDAO restaurantDao):
    restaurantDao(restaurantDao) {}

std::vector<std::string> AvailableRestaurants::at(std::string hour) {
    std::vector<std::string> opened;

    for (Restaurant restaurant : restaurantDao.all()) {
        if (restaurant.isOpenAt(hour)) {
            opened.push_back(restaurant.getName());
        }
    }

    return opened;
}
