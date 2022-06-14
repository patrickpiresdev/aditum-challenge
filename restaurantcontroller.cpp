#include "restaurantcontroller.h"
#include "restaurant.h"

#include <iostream>
#include <vector>

RestaurantController::RestaurantController(std::vector<Restaurant> restaurants):
    restaurants(restaurants) {}

void RestaurantController::available(const QString& hour) {
    std::cout << "*** ALL RESTAURANTS (" << restaurants.size() << ") ***" << std::endl;
    for (Restaurant restautant : restaurants) {
        std::cout << restautant.getName() << std::endl;
    }
}
