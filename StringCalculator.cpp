#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <regex>
#include <numeric>

// Helper method to extract delimiter; default is ",|\n"
std::string StringCalculator::extractDelimiter(const std::string& input) {
    if (input.rfind("//", 0) == 0) {
        size_t newlinePos = input.find('\n');
        return input.substr(2, newlinePos - 2);  // Extract custom delimiter
    }
    return ",|\n";  // Default delimiters
}

// Helper method to split numbers using a delimiter
std::vector<std::string> StringCalculator::splitNumbers(const std::string& input, const std::string& delimiter) {
    std::regex delimiterRegex(delimiter);
    std::sregex_token_iterator iter(input.begin(), input.end(), delimiterRegex, -1);
    std::sregex_token_iterator end;
    return {iter, end};
}

// Helper method to collect negative numbers
std::vector<int> StringCalculator::collectNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int num : numbers) {
        if (num < 0) {
            negatives.push_back(num);
        }
    }
    return negatives;
}

// Helper method to throw exception if negatives are found
void StringCalculator::handleNegatives(const std::vector<int>& negatives) {
    if (!negatives.empty()) {
        throw std::runtime_error("Negatives not allowed: " +
            std::accumulate(negatives.begin(), negatives.end(), std::string(),
                            [](const std::string& acc, int n) {
                                return acc + (acc.empty() ? "" : ",") + std::to_string(n);
                            }));
    }
}

// Helper method to parse numbers from string input
std::vector<int> StringCalculator::parseNumbers(const std::string& input) {
    std::string delimiter = extractDelimiter(input);
    std::string numbersPart = input.rfind("//", 0) == 0 ? input.substr(input.find('\n') + 1) : input;

    std::vector<std::string> tokens = splitNumbers(numbersPart, delimiter);
    std::vector<int> numbers;

    for (const std::string& token : tokens) {
        if (!token.empty()) {
            int num = std::stoi(token);
            if (num <= 1000) {
                numbers.push_back(num);
            }
        }
    }

    std::vector<int> negatives = collectNegatives(numbers);
    handleNegatives(negatives);

    return numbers;
}

// Main method to add numbers
int StringCalculator::add(const std::string& input) {
    if (input.empty()) return 0;

    std::vector<int> numbers = parseNumbers(input);
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}
