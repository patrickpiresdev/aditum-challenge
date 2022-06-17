#ifndef AVAILABLERESTAURANTSTEST_H
#define AVAILABLERESTAURANTSTEST_H

#include "../testutils.h"

#include "../../main/service/availablerestaurants.h"

#include <fstream>

std::vector<std::string> fakeData() {
    return {
        "\"restaurant 1\",\"6:00-14:00\"",
        "\"restaurant 2\",\"18:00-22:30\"",
        "\"restaurant 3\",\"8:00-20:00\"",
        "\"restaurant 4\",\"24:00-7:00\""
    };
}

void createDataFile() {
    std::ofstream file;
    file.open("./fakedata.csv");

    std::string header = "\"RestaurantName\",\"OpenHours\"";
    file << header << '\n';

    for (std::string line : fakeData())
        file << line << '\n';

    file.close();
}

void deleteDataFile() {
    remove("./fakedata.csv");
}

bool contains(std::vector<std::string> l, std::string s) {
    for (std::string i : l)
        if (i == s) return true;
    return false;
}

bool contains(std::vector<std::string> l1, std::vector<std::string> l2) {
    for (std::string s : l2)
        if (!contains(l1, s)) return false;
    return true;
}

void availableRestaurantsInTheMorning(AvailableRestaurants& availableRestaurants) {
    startingUnitTest("AVAILABLE RESTAURANTS IN THE MORNING");
    std::vector<std::string> restaurants = availableRestaurants.at("6:00");
    std::vector<std::string> expected = { "restaurant 1", "restaurant 4" };
    assertTrue(restaurants.size() == 2);
    assertTrue(contains(restaurants, expected));
}

void availableRestaurantsInTheAfternoon(AvailableRestaurants& availableRestaurants) {
    startingUnitTest("AVAILABLE RESTAURANTS IN THE AFTERNOON");
    std::vector<std::string> restaurants = availableRestaurants.at("19:00");
    std::vector<std::string> expected = { "restaurant 2", "restaurant 3" };
    assertTrue(restaurants.size() == 2);
    assertTrue(contains(restaurants, expected));
}

void availableRestaurantsInTheLateNight(AvailableRestaurants& availableRestaurants) {
    startingUnitTest("RESTAURANTS AVAILABLE IN THE LATE NIGHT");
    std::vector<std::string> restaurants = availableRestaurants.at("2:00");
    std::vector<std::string> expected = { "restaurant 4" };
    assertTrue(restaurants.size() == 1);
    assertTrue(contains(restaurants, expected));
}

void testWhenThereAreNoRestaurantsAvailable(AvailableRestaurants& availableRestaurants) {
    startingUnitTest("THERE ARE NO RESTAURANTS AVAILABLE");
    std::vector<std::string> restaurants = availableRestaurants.at("23:00");
    assertTrue(restaurants.size() == 0);
}

void availableRestaurantsTests() {
    startingTestsFor("AVAILABLE RESTAURANTS SERVICE");

    createDataFile();
    RestaurantDAO mockedDao("./fakedata.csv");
    AvailableRestaurants availableRestaurants(mockedDao);

    availableRestaurantsInTheMorning(availableRestaurants);
    availableRestaurantsInTheAfternoon(availableRestaurants);
    availableRestaurantsInTheLateNight(availableRestaurants);
    testWhenThereAreNoRestaurantsAvailable(availableRestaurants);

    deleteDataFile();
}

#endif
