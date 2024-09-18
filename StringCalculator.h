#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    // Public method to add numbers from the input string
    int add(const std::string& input);

private:
    // Extracts delimiter from the input
    std::string extractDelimiter(const std::string& input);

    // Splits the numbers part of the input based on delimiter
    std::vector<std::string> splitNumbers(const std::string& input, const std::string& delimiter);

    // Parses numbers from the input string
    std::vector<int> parseNumbers(const std::string& input);

    // Collects negative numbers from the list
    std::vector<int> collectNegatives(const std::vector<int>& numbers);

    // Throws an exception if any negative numbers are found
    void handleNegatives(const std::vector<int>& negatives);
};

#endif // STRING_CALCULATOR_H
