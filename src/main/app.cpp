#include <vector>
#include <string>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>

#include "./dao/restaurantdao.h"
#include "./service/availablerestaurants.h"
#include "./controller/restaurantcontroller.h"

const std::string DEFAULT_DATAFILE_NAME = "restaurant-hours.csv";

std::string getDataFilePath() {
    QString curPath = QDir::currentPath();
    QStringList curPathSplitted = curPath.split('/');

    std::string dataFilePath = "";
    for (int i = 0; i < curPathSplitted.size()-1; i++) {
        dataFilePath.append(curPathSplitted[i].toStdString());
        dataFilePath.append("/");
    }

    dataFilePath.append("aditum-challenge/data/");
    dataFilePath.append(DEFAULT_DATAFILE_NAME);

    return dataFilePath;
}

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

    RestaurantDAO restaurantDao(getDataFilePath());
    AvailableRestaurants availableRestaurants(restaurantDao);
    RestaurantController restaurantController(availableRestaurants);
    engine.rootContext()->setContextProperty("restaurantController", &restaurantController);

    return app.exec();
}
