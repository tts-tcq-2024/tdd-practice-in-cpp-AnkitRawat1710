#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <vector>

class StringCalculator
{
public:
    int validateNumberRange(int number);
    int ensurePositive(int number);
    std::string formatStringForDelimiters(const std::string& input);
    int handleWhitespaceErrors(const std::string& token);
    int computeSum(const std::string& input);
};

#endif // STRING_CALCULATOR_H
