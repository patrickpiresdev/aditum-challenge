#ifndef HOUR_H
#define HOUR_H

#include <string>

class Hour {
    std::string hourStr;
public:
    Hour(std::string hourStr);
    std::string value() const;
    int compare(const Hour& another) const;
    bool equal(const Hour& another) const;
};

#endif // HOUR_H
