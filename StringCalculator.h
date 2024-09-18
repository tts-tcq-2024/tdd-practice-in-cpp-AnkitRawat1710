#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& input);

private:
    std::string extractDelimiter(const std::string& input);
    std::vector<std::string> splitNumbers(const std::string& input, const std::string& delimiter); // New method declaration
    void checkForNegatives(const std::vector<int>& numbers); // New method declaration
    std::vector<int> parseNumbers(const std::string& input);
};

#endif // STRINGCALCULATOR_H
