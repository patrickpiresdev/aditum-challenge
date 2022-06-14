#include "restaurantcontroller.h"
#include <iostream>

RestaurantController::RestaurantController(QObject *parent)
    : QObject{parent} {}

void RestaurantController::available(const QString& hour) {
    std::cout << hour.toStdString() << std::endl;
}
