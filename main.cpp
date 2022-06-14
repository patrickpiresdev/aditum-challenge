#include <vector>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "restaurantdao.h"
#include "availablerestaurants.h"
#include "restaurantcontroller.h"

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    RestaurantDAO restaurantDao("C:/Users/patri/Downloads/restaurant-hours.csv");
    AvailableRestaurants availableRestaurants(restaurantDao);
    RestaurantController restaurantController(availableRestaurants);
    engine.rootContext()->setContextProperty("restaurantController", &restaurantController);

    return app.exec();
}
