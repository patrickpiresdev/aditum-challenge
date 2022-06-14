#include "restaurantcontroller.h"

RestaurantController::RestaurantController(AvailableRestaurants availableRestaurants):
    availableRestaurants(availableRestaurants) {}

void RestaurantController::available(const QString& hour) {
    std::vector<std::string> restaurants = availableRestaurants.at(hour.toStdString());
    std::cout << std::endl << "*** ALL RESTAURANTS (" << restaurants.size() << ") ***" << std::endl;
    for (std::string restautant : restaurants) {
        std::cout << restautant << std::endl;
    }
}
