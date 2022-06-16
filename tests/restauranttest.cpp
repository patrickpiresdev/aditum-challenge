#include <iostream>

#include "../restaurant.h"

#include "testutils.h"

void ordinaryRestaurantShouldBeOpen() {
    std::cout << "=== ORDINARY RESTAURANT SHOULD BE OPEN TEST ===" << std::endl;
    Restaurant restaurant("restaurant", "9:00", "18:00");
    assertTrue(restaurant.isOpenAt("9:00"));
    assertTrue(restaurant.isOpenAt("13:30"));
    assertTrue(restaurant.isOpenAt("18:00"));
}

void ordinaryRestaurantShoudBeClosed() {
    std::cout << "=== ORDINARY RESTAURANT SHOULD BE CLOSED TEST ===" << std::endl;
    Restaurant restaurant("restaurant", "9:00", "18:00");
    assertTrue(!restaurant.isOpenAt("8:59"));
    assertTrue(!restaurant.isOpenAt("18:01"));
}

void lateNightRestaurantShouldBeOpen() {
    std::cout << "=== LATE NIGHT RESTAURANT SHOULD BE OPEN TEST ===" << std::endl;
    Restaurant restaurant("restaurant", "20:00", "5:00");
    assertTrue(restaurant.isOpenAt("20:00"));
    assertTrue(restaurant.isOpenAt("24:30"));
    assertTrue(restaurant.isOpenAt("5:00"));
}

void lateNightRestaurantShouldBeClosed() {
    std::cout << "=== LATE NIGHT RESTAURANT SHOULD BE CLOSED TEST ===" << std::endl;
    Restaurant restaurant("restaurant", "20:00", "5:00");
    assertTrue(!restaurant.isOpenAt("19:59"));
    assertTrue(!restaurant.isOpenAt("5:01"));
}

int main() {
    startingTestsFor("RESTAURANT");
    ordinaryRestaurantShouldBeOpen();
    std::cout << std::endl;
    ordinaryRestaurantShoudBeClosed();
    std::cout << std::endl;
    lateNightRestaurantShouldBeOpen();
    std::cout << std::endl;
    lateNightRestaurantShouldBeClosed();
}
