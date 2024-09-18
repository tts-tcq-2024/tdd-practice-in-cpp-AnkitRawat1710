#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);  // Main method to add numbers from a string.

private:
    std::vector<int> parseNumbers(const std::string& input);
    std::string extractDelimiter(const std::string& input);
};

#endif  // STRINGCALCULATOR_H
