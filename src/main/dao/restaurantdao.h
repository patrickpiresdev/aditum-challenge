#ifndef RESTAURANTDAO_H
#define RESTAURANTDAO_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "../model/restaurant.h"

class RestaurantDAO {
    std::string datafilePath;

    void skipHeader(std::ifstream&);
public:
    RestaurantDAO(std::string datafilePath);
    std::vector<Restaurant*> all();
};

#endif // RESTAURANTDAO_H
