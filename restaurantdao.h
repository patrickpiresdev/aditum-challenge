#ifndef RESTAURANTDAO_H
#define RESTAURANTDAO_H

#include "restaurant.h"

#include <vector>

class RestaurantDAO {
public:
    RestaurantDAO();
    std::vector<Restaurant> all();
};

#endif // RESTAURANTDAO_H
