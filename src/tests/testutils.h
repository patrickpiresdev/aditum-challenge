#include <iostream>
#include <string>

void startingTestsFor(std::string unitName) {
    std::cout << "================== " << unitName << " TESTS ==================" << std::endl;
}

void assertTrue(bool expression) {
    std::cout << '\t' << (expression == true ? "SUCCESS" : "FAIL") << std::endl;
}
