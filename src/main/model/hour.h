#ifndef HOUR_H
#define HOUR_H

#include <string>
#include <cmath>

class Hour {
    int hourValue;

    int toInt(char);
    int toInt(const std::string& hourStr);
public:
    Hour(const std::string& hourStr);
    int value() const;
    int compare(const Hour& another) const;
    bool equal(const Hour& another) const;
};

#endif // HOUR_H
