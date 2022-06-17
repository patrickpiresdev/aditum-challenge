#ifndef RESTAURANTTEST_H
#define RESTAURANTTEST_H

#include <iostream>

#include "../../main/model/restaurant.h"
#include "../../main/model/hour.h"

#include "../testutils.h"

void ordinaryRestaurantShouldBeOpen() {
    startingUnitTest("ORDINARY RESTAURANT SHOULD BE OPEN");
    Restaurant restaurant("restaurant", "9:00", "18:00");
    Hour opening("9:00");
    Hour mid("13:30");
    Hour closing("18:00");
    assertTrue(restaurant.isOpenAt(opening));
    assertTrue(restaurant.isOpenAt(mid));
    assertTrue(restaurant.isOpenAt(closing));
}

void ordinaryRestaurantShoudBeClosed() {
    startingUnitTest("ORDINARY RESTAURANT SHOULD BE CLOSED");
    Restaurant restaurant("restaurant", "9:00", "18:00");
    Hour rightBeforeOpening("8:59");
    Hour rightAfterClosing("18:01");
    assertTrue(!restaurant.isOpenAt(rightBeforeOpening));
    assertTrue(!restaurant.isOpenAt(rightAfterClosing));
}

void lateNightRestaurantShouldBeOpen() {
    startingUnitTest("LATE NIGHT RESTAURANT SHOULD BE OPEN");
    Restaurant restaurant("restaurant", "20:00", "5:00");
    Hour opening("20:00");
    Hour mid("24:30");
    Hour closing("5:00");
    assertTrue(restaurant.isOpenAt(opening));
    assertTrue(restaurant.isOpenAt(mid));
    assertTrue(restaurant.isOpenAt(closing));
}

void lateNightRestaurantShouldBeClosed() {
    startingUnitTest("LATE NIGHT RESTAURANT SHOULD BE CLOSED");
    Restaurant restaurant("restaurant", "20:00", "5:00");
    Hour rightBeforeOpening("19:59");
    Hour rightAfterClosing("5:01");
    assertTrue(!restaurant.isOpenAt(rightBeforeOpening));
    assertTrue(!restaurant.isOpenAt(rightAfterClosing));
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
