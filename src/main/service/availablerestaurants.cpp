#include "availablerestaurants.h"

AvailableRestaurants::AvailableRestaurants(RestaurantDAO restaurantDao):
    restaurantDao(restaurantDao) {}

std::vector<std::string> AvailableRestaurants::at(std::string hour) {
    std::vector<std::string> opened;
    std::vector<Restaurant*> restaurants = restaurantDao.all();

    if (restaurants.empty()) return opened;

    Restaurant* restaurant;
    while (!restaurants.empty()) {
        restaurant = restaurants.back();
        if (restaurant->isOpenAt(hour)) {
            opened.push_back(restaurant->getName());
        }
        restaurants.pop_back();
        delete restaurant;
    }

    return opened;
}
