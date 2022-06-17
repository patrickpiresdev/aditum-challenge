#ifndef HOUR_H
#define HOUR_H

#include <string>
#include <cmath>

class Hour {
    int hourValue;

    int toInt(char);
    int toInt(const std::string& hourStr);
    int compare(int another) const;
public:
    Hour(const std::string& hourStr);
    int value() const;
    int compare(const Hour& another) const;
    bool equal(const Hour& another) const;
    bool inRange(const Hour& start, const Hour& end) const;
};

#endif // HOUR_H
