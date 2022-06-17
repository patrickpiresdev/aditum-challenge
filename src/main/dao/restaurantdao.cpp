#include "restaurantdao.h"

RestaurantDAO::RestaurantDAO(std::string datafilePath):
    datafilePath(datafilePath) {}

void RestaurantDAO::skipHeader(std::ifstream& ifs) {
    std::string line;
    std::getline(ifs, line);
}

std::vector<Restaurant*> RestaurantDAO::all() {
    std::ifstream filestream;

    filestream.open(datafilePath);
    if (!filestream.is_open()) {
        std::cout << "Something went wrong on trying to read file: " << datafilePath << std::endl;
        exit(1);
    }

    std::vector<Restaurant*> restaurants;
    std::string line;
    skipHeader(filestream);

    while (!filestream.eof()) {
        std::getline(filestream, line);
        if (line.compare("\n") != 0 && line.compare("") != 0)
            restaurants.push_back(Restaurant::from(line));
    }

    filestream.close();
    return restaurants;
}
