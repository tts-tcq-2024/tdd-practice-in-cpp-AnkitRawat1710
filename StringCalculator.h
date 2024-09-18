#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <stdexcept>

class StringCalculator
{
public:
    int checkIfLessThanThousand(int num);
    int validateNonNegative(int num);
    std::string adjustDelimiters(std::string input);
    int handleWhitespace(std::string token);
    int add(std::string input);  // Function name should be `add`
};
#endif // STRINGCALCULATOR_H
