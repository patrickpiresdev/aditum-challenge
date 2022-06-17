#include "hour.h"

Hour::Hour(std::string hourStr):
    hourStr(hourStr) {}

std::string Hour::value() const {
    return hourStr;
}

int Hour::compare(const Hour& another) const {
    std::string anotherStr = another.value();
    if (hourStr.length() > anotherStr.length()) return 1;
    if (hourStr.length() < anotherStr.length()) return -1;
    return hourStr.compare(anotherStr);
}

bool Hour::equal(const Hour& another) const {
    return compare(another) == 0;
}
