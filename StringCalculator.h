#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::vector<int> parseNumbers(const std::string& numbers, const std::string& delimiter); //Parses numbers from the input string
    std::string getCustomDelimiter(const std::string& input); //Extracts the custom delimiter from the input string
    std::string getNumberString(const std::string& input); //Extracts the number part of the input string
    int sumNumbers(const std::vector<int>& numbers); //Calculates the sum of a vector of number
    void validateNumbers(const std::vector<int>& numbers); //Validates the numbers in the vector
    std::vector<int> findNegativeNumbers(const std::vector<int>& numbers); //Finds negative numbers in the vector
    void throwIfNegatives(const std::vector<int>& negatives); //Throws an exception if negative numbers are found
    int toInt(const std::string& number); //Converts a string to an integer
    std::vector<int> filterLargeNumbers(const std::vector<int>& numbers); //Filters out numbers greater than 1000
};

#endif
