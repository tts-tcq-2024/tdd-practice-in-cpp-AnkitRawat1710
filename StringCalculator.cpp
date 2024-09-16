#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>

// Extracts the delimiter and input string.
// If a custom delimiter is provided, updates the delimiter and input.
std::string StringCalculator::getDelimiterAndInput(const std::string& numbers, std::string& input) {
    std::string delimiter = ",|\n";  // Default delimiters: comma and newline.
    
    // Check for custom delimiter.
    if (numbers.rfind("//", 0) == 0) {
        size_t newlinePos = numbers.find('\n');
        delimiter = numbers.substr(2, newlinePos - 2);  // Get custom delimiter.
        input = numbers.substr(newlinePos + 1);  // Remaining input after the delimiter line.
    } else {
        input = numbers;
    }

    return delimiter;
}

// Splits the input string into tokens based on the given delimiter.
// Handles multiple delimiters using a simple string find and substr method.
std::vector<std::string> StringCalculator::split(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = input.find_first_of(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find_first_of(delimiter, start);
    }
    tokens.push_back(input.substr(start));
    return tokens;
}

// Checks for negative numbers and throws an exception if any are found.
void StringCalculator::checkNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int num : numbers) {
        if (num < 0) negatives.push_back(num);
    }
    
    if (!negatives.empty()) {
        std::string message = "negatives not allowed: ";
        for (int n : negatives) message += std::to_string(n) + " ";
        throw std::runtime_error(message);
    }
}

// Main method to add numbers in a string, handling custom delimiters, newlines, and ignoring numbers > 1000.
int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) return 0;  // Return 0 for an empty string.

    std::string input;
    std::string delimiter = getDelimiterAndInput(numbers, input);

    // Split input into tokens using the delimiter.
    std::vector<std::string> tokens = split(input, delimiter);
    int sum = 0;
    std::vector<int> nums;

    for (const auto& token : tokens) {
        if (token.empty()) continue;
        int num = std::stoi(token);
        if (num <= 1000) nums.push_back(num);
    }

    // Check for negatives.
    checkNegatives(nums);

    // Sum the valid numbers.
    for (int num : nums) sum += num;

    return sum;
}


