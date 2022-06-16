#include "restaurantcontroller.h"

RestaurantController::RestaurantController(AvailableRestaurants availableRestaurants):
    availableRestaurants(availableRestaurants) {}

QStringList RestaurantController::available(const QString& hour) {
    QStringList l;

    for (std::string restaurant : availableRestaurants.at(hour.toStdString())) {
        l << QString::fromUtf8(restaurant.c_str());
    }

    return l;
}
