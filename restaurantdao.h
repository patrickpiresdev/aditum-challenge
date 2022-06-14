#ifndef RESTAURANTDAO_H
#define RESTAURANTDAO_H

#include <vector>

#include "restaurant.h"

class RestaurantDAO {
public:
    RestaurantDAO();
    std::vector<Restaurant> all();
};

#endif // RESTAURANTDAO_H
