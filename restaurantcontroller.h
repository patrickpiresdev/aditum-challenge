#ifndef RESTAURANTCONTROLLER_H
#define RESTAURANTCONTROLLER_H

#include <QObject>

#include <vector>

#include "restaurant.h"
#include "restaurantdao.h"

class RestaurantController : public QObject {
    Q_OBJECT
    RestaurantDAO restaurantDao;
public:
    explicit RestaurantController(RestaurantDAO restaurantDao);
public slots:
    void available(const QString& hour);
};

#endif // RESTAURANTCONTROLLER_H
