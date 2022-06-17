#ifndef RESTAURANTCONTROLLER_H
#define RESTAURANTCONTROLLER_H

#include <string>

#include <QObject>
#include <QString>
#include <QStringList>

#include "../service/availablerestaurants.h"

class RestaurantController : public QObject {
    Q_OBJECT
    AvailableRestaurants availableRestaurants;
public:
    RestaurantController(AvailableRestaurants availableRestaurants);
public slots:
    QStringList available(const QString& hour);
};

#endif // RESTAURANTCONTROLLER_H
