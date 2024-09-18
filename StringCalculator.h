#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>

class StringCalculator
{
public:
    // Method to validate if the number is below a certain threshold
    int validateNumberThreshold(int number);

    // Method to ensure the number is positive and process negative numbers
    int processPositiveNumber(int number);

    // Method to format the input string by replacing delimiters
    std::string formatStringForDelimiters(const std::string& input);

    // Method to handle whitespace and conversion errors
    int convertTokenToNumber(const std::string& token);

    // Method to compute the sum of numbers in the input string
    int computeSum(const std::string& input);
};

#endif // STRINGCALCULATOR_H
