#include "restaurantdao.h"

RestaurantDAO::RestaurantDAO(std::string datafilePath):
    datafilePath(datafilePath) {}

std::vector<Restaurant*> getFromFile(std::string datafilePath) {
    std::ifstream filestream;
    filestream.open(datafilePath);

    if (!filestream.is_open()) {
        std::cout << "Something went wrong on trying to read file: " << datafilePath << std::endl;
        exit(1);
    }

    std::vector<Restaurant*> restaurants;
    std::string line;
    std::getline(filestream, line); // skip first line -> header

    while (!filestream.eof()) {
        restaurants.push_back(Restaurant::from(line));
        std::getline(filestream, line);
    }

    filestream.close();
    return restaurants;
}

std::vector<Restaurant*> RestaurantDAO::all() {
    return getFromFile(datafilePath);
}
