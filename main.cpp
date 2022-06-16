#include <vector>
#include <string>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "restaurantdao.h"
#include "availablerestaurants.h"
#include "restaurantcontroller.h"

// TODO: transform in relative path
const std::string DEFAULT_DATAFILE_PATH = "C:\\Users\\patri\\Documents\\restaurant-hours.csv";

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

    RestaurantDAO restaurantDao(DEFAULT_DATAFILE_PATH);
    AvailableRestaurants availableRestaurants(restaurantDao);
    RestaurantController restaurantController(availableRestaurants);
    engine.rootContext()->setContextProperty("restaurantController", &restaurantController);

    return app.exec();
}
