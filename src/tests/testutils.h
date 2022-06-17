#ifndef TESTUTILS_H
#define TESTUTILS_H

#include <iostream>
#include <string>

void startingTestsFor(std::string testName) {
    std::cout << "\n================== " << testName << " TESTS ==================" << std::endl;
}

void startingUnitTest(std::string unitName) {
    std::cout << "=== UNIT TEST: " << unitName << " ===" << std::endl;
}

void assertTrue(bool expression) {
    std::cout << '\t' << (expression == true ? "SUCCESS" : "FAIL") << std::endl;
}

#endif