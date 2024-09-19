// StringCalculator.h

#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::vector<int> extractNumbers(const std::string& numbers, const std::string& delimiter);
};

#endif
