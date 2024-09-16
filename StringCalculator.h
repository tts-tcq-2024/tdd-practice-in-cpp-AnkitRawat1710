#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::string getDelimiterAndInput(const std::string& numbers, std::string& input);
    std::vector<std::string> split(const std::string& input, const std::string& delimiter);
    void checkNegatives(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H

