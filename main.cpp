#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <vector>

#include "restaurantcontroller.h"
#include "restaurant.h"

std::vector<Restaurant> mockRestaurantData() {
    return {
        Restaurant("Kushi Tsuru", "11:30", "21:00"),
        Restaurant("Osakaya Restaurant", "11:30", "21:00"),
        Restaurant("The Stinking Rose", "9:00", "22:00"),
        Restaurant("McCormick & Kuleto's", "11:30", "23:00"),
        Restaurant("Mifune Restaurant", "11:00", "22:00"),
        Restaurant("The Cheesecake Factory", "11:00", "23:00"),
        Restaurant("New Delhi Indian Restaurant", "11:00", "17:30"),
        Restaurant("Iroha Restaurant", "11:00", "17:30"),
        Restaurant("Rose Pistola", "9:00", "22:00"),
        Restaurant("Alioto's Restaurant", "11:00", "23:00"),
        Restaurant("Canton Seafood & Dim Sum Restaurant", "10:30", "22:30"),
        Restaurant("All Season Restaurant", "10:00", "21:30"),
        Restaurant("Bombay Indian Restaurant", "11:30", "21:00"),
        Restaurant("Sam's Grill & Seafood Restaurant", "11:30", "21:00"),
        Restaurant("2G Japanese Brasserie", "11:30", "23:00"),
        Restaurant("Restaurant Lulu", "11:30", "23:00"),
        Restaurant("Sudachi", "9:00", "22:00"),
        Restaurant("Hanuri", "11:00", "23:00"),
        Restaurant("Herbivore", "11:00", "17:30"),
        Restaurant("Penang Garden", "11:00", "17:30"),
        Restaurant("John's Grill", "9:00", "22:00"),
        Restaurant("Quan Bac", "11:30", "23:00"),
        Restaurant("Bamboo Restaurant", "9:00", "22:00"),
        Restaurant("Burger Bar", "11:00", "23:00"),
        Restaurant("Blu Restaurant", "11:00", "17:30"),
        Restaurant("Naan 'N' Curry", "11:00", "17:30"),
        Restaurant("Shanghai China Restaurant", "9:00", "22:00"),
        Restaurant("Tres", "11:30", "23:00"),
        Restaurant("Isobune Sushi", "9:00", "22:00"),
        Restaurant("Viva Pizza Restaurant", "11:00", "23:00"),
        Restaurant("Far East Cafe", "11:00", "17:30"),
        Restaurant("Parallel 37", "11:00", "17:30"),
        Restaurant("Bai Thong Thai Cuisine", "9:00", "22:00"),
        Restaurant("Alhamra", "11:30", "23:00"),
        Restaurant("A-1 Cafe Restaurant", "9:00", "22:00"),
        Restaurant("Nick's Lighthouse", "11:00", "23:00"),
        Restaurant("Paragon Restaurant & Bar", "11:00", "17:30"),
        Restaurant("Chili Lemon Garlic", "11:00", "17:30"),
        Restaurant("Bow Hon Restaurant", "9:00", "22:00"),
        Restaurant("San Dong House", "11:30", "23:00"),
        Restaurant("Thai Stick Restaurant", "9:00", "22:00"),
        Restaurant("Cesario's", "11:00", "23:00"),
        Restaurant("Colombini Italian Cafe Bistro", "11:00", "17:30"),
        Restaurant("Sabella & La Torre", "11:00", "17:30"),
        Restaurant("Soluna Cafe and Lounge", "9:00", "22:00"),
        Restaurant("Tong Palace", "11:30", "23:00"),
        Restaurant("India Garden Restaurant", "9:00", "22:00"),
        Restaurant("Sapporo-Ya Japanese Restaurant", "11:00", "23:00"),
        Restaurant("Santorini's Mediterranean Cuisine", "11:00", "17:30"),
        Restaurant("Kyoto Sushi", "11:00", "17:30"),
        Restaurant("Marrakech Moroccan Restaurant", "9:00", "22:00")
    };
}

int main(int argc, char *argv[])
{
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

    RestaurantController restaurantController(mockRestaurantData());
    engine.rootContext()->setContextProperty("restaurantController", &restaurantController);

    return app.exec();
}
