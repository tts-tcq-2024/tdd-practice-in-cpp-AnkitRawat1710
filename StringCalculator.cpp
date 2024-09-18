#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <regex>
#include <numeric>  // Add this line for std::accumulate

// Helper method to extract delimiter; default is ",|\n"
std::string StringCalculator::extractDelimiter(const std::string& input) {
    if (input.rfind("//", 0) == 0) {
        size_t newlinePos = input.find('\n');
        return input.substr(2, newlinePos - 2);  // Extract custom delimiter
    }
    return ",|\n";  // Default delimiters
}

// Helper method to parse numbers and handle exceptions
std::vector<int> StringCalculator::parseNumbers(const std::string& input) {
    std::string delimiter = extractDelimiter(input);
    std::string numbersPart = input.rfind("//", 0) == 0 ? input.substr(input.find('\n') + 1) : input;

    std::regex delimiterRegex(delimiter);
    std::sregex_token_iterator iter(numbersPart.begin(), numbersPart.end(), delimiterRegex, -1);
    std::sregex_token_iterator end;

    std::vector<int> numbers;
    std::vector<int> negatives;

    for (; iter != end; ++iter) {
        if (!iter->str().empty()) {
            int num = std::stoi(iter->str());
            if (num < 0) {
                negatives.push_back(num);
            } else if (num <= 1000) {
                numbers.push_back(num);
            }
        }
    }

    if (!negatives.empty()) {
        throw std::runtime_error("Negatives not allowed: " + std::accumulate(negatives.begin(), negatives.end(), std::string(),
                         [](const std::string& acc, int n) { return acc + (acc.empty() ? "" : ",") + std::to_string(n); }));
    }

    return numbers;
}

// Main method to add numbers
int StringCalculator::add(const std::string& input) {
    if (input.empty()) return 0;

    std::vector<int> numbers = parseNumbers(input);
    int sum = 0;
    for (int num : numbers) sum += num;

    return sum;
}
