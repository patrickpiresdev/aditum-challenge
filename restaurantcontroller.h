#ifndef RESTAURANTCONTROLLER_H
#define RESTAURANTCONTROLLER_H

#include <QObject>

class RestaurantController : public QObject
{
    Q_OBJECT
public:
    explicit RestaurantController(QObject *parent = nullptr);
public slots:
    void available(const QString& hour);

signals:

};

#endif // RESTAURANTCONTROLLER_H
