#ifndef RESTAURANTCONTROLLER_H
#define RESTAURANTCONTROLLER_H

#include <QObject>

#include <vector>

#include "restaurant.h"

class RestaurantController : public QObject
{
    Q_OBJECT
    std::vector<Restaurant> restaurants;
public:
    explicit RestaurantController(std::vector<Restaurant> restaurants);
public slots:
    void available(const QString& hour);

signals:

};

#endif // RESTAURANTCONTROLLER_H
