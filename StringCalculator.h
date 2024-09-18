#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);  // Main method to add numbers from a string.

private:
    // Helper methods
    std::vector<std::string> splitString(const std::string& input, const std::string& delimiter);
    std::string getDelimiter(const std::string& numbers);
    std::string getNumberSection(const std::string& numbers);
    std::vector<int> parseNumbers(const std::string& numbers, const std::string& delimiter);
};

#endif  // STRINGCALCULATOR_H

