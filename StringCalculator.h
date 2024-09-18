#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>

class StringCalculator
{
public:
    // Method to limit numbers to a maximum value
    int limitToMaxValue(int number);

    // Method to process and filter numbers
    int processNumber(int number);

    // Method to adjust the input string based on custom delimiters
    std::string adjustStringDelimiters(const std::string& input);

    // Method to convert tokens to numbers and handle errors
    int handleTokenConversion(const std::string& token);

    // Method to compute the sum of numbers in a given string
    int computeSumFromString(const std::string& input);
};

#endif // STRING_CALCULATOR_H
