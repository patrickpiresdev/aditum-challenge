#include "restaurantcontroller.h"

#include <iostream>

RestaurantController::RestaurantController(RestaurantDAO restaurantDao):
    restaurantDao(restaurantDao) {}

void RestaurantController::available(const QString& hour) {
    std::vector<Restaurant> restaurants = restaurantDao.all();
    std::cout << "*** ALL RESTAURANTS (" << restaurants.size() << ") ***" << std::endl;
    for (Restaurant restautant : restaurants) {
        std::cout << restautant.getName() << std::endl;
    }
}
