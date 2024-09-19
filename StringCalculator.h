#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& numbers); // Adds numbers from a string

private:
    std::vector<int> parseNumbers(const std::string& numbers, const std::string& delimiter); // Parses numbers from a string
    std::string getCustomDelimiter(const std::string& input); // Extracts the custom delimiter
    std::string getNumberString(const std::string& input); // Extracts the number part of the string
    int sumNumbers(const std::vector<int>& numbers); // Sums up a vector of numbers
    void validateNumbers(const std::vector<int>& numbers); // Validates the numbers
    std::string negativesToString(const std::vector<int>& negatives); // Converts negatives to a string
    int toInt(const std::string& number); // Converts a string to an integer
    std::vector<int> filterLargeNumbers(const std::vector<int>& numbers); // Filters out large numbers
};

#endif
