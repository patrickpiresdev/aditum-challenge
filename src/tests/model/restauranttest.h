#ifndef RESTAURANTTEST_H
#define RESTAURANTTEST_H

#include <iostream>

#include "../../main/model/restaurant.h"

#include "../testutils.h"

void ordinaryRestaurantShouldBeOpen() {
    startingUnitTest("ORDINARY RESTAURANT SHOULD BE OPEN");
    Restaurant restaurant("restaurant", "9:00", "18:00");
    assertTrue(restaurant.isOpenAt("9:00"));
    assertTrue(restaurant.isOpenAt("13:30"));
    assertTrue(restaurant.isOpenAt("18:00"));
}

void ordinaryRestaurantShoudBeClosed() {
    startingUnitTest("ORDINARY RESTAURANT SHOULD BE CLOSED");
    Restaurant restaurant("restaurant", "9:00", "18:00");
    assertTrue(!restaurant.isOpenAt("8:59"));
    assertTrue(!restaurant.isOpenAt("18:01"));
}

void lateNightRestaurantShouldBeOpen() {
    startingUnitTest("LATE NIGHT RESTAURANT SHOULD BE OPEN");
    Restaurant restaurant("restaurant", "20:00", "5:00");
    assertTrue(restaurant.isOpenAt("20:00"));
    assertTrue(restaurant.isOpenAt("24:30"));
    assertTrue(restaurant.isOpenAt("5:00"));
}

void lateNightRestaurantShouldBeClosed() {
    startingUnitTest("LATE NIGHT RESTAURANT SHOULD BE CLOSED");
    Restaurant restaurant("restaurant", "20:00", "5:00");
    assertTrue(!restaurant.isOpenAt("19:59"));
    assertTrue(!restaurant.isOpenAt("5:01"));
}

void restaurantTests() {
    startingTestsFor("RESTAURANT");
    ordinaryRestaurantShouldBeOpen();
    std::cout << std::endl;
    ordinaryRestaurantShoudBeClosed();
    std::cout << std::endl;
    lateNightRestaurantShouldBeOpen();
    std::cout << std::endl;
    lateNightRestaurantShouldBeClosed();
}

#endif
