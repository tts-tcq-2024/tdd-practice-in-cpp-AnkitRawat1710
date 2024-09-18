#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>

class StringCalculator {
public:
    // Method to compute the sum from the input string
    int computeSumFromString(const std::string& input);

private:
    // Helper method to check if a number is below 1000
    int limitToThousand(int num);

    // Helper method to process the input string for delimiters
    std::string replaceDelimiters(std::string input);

    // Helper method to handle whitespace and convert to integer
    int handleWhitespaceAndConvert(const std::string& token);

    // Helper method to handle negative numbers and throw exceptions
    void validateNoNegatives();
};

#endif // STRINGCALCULATOR_H
