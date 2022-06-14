#ifndef RESTAURANTCONTROLLER_H
#define RESTAURANTCONTROLLER_H

#include <iostream>
#include <vector>
#include <string>

#include <QObject>

#include "availablerestaurants.h"

class RestaurantController : public QObject {
    Q_OBJECT
    AvailableRestaurants availableRestaurants;
public:
    RestaurantController(AvailableRestaurants availableRestaurants);
public slots:
    void available(const QString& hour);
};

#endif // RESTAURANTCONTROLLER_H
