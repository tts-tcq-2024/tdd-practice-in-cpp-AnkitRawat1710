#include "StringCalculator.h"
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <string>

// Custom exception class for error handling
class CalculationException : public std::runtime_error {
public:
    explicit CalculationException(const std::string& message)
        : std::runtime_error(message) {}
};

// Global variables to track negative numbers
std::vector<int> negativeNumbers;
bool hasNegativeNumbers = false;

void detectAlphabetErrors(const std::string& token) {
    for (char ch : token) {
        if (isalpha(ch)) {
            throw CalculationException("Alphabets not allowed: " + token);
        }
    }
}

void validateNoNegatives() {
    if (hasNegativeNumbers) {
        std::string message = "Negatives not allowed: ";
        for (size_t i = 0; i < negativeNumbers.size(); ++i) {
            message += std::to_string(negativeNumbers[i]);
            if (i < negativeNumbers.size() - 1) {
                message += ", ";
            }
        }
        throw CalculationException(message);
    }
}

int StringCalculator::limitToThousand(int num) {
    return (num >= 1000) ? 0 : num;
}

int StringCalculator::handleWhitespaceAndConvert(const std::string& token) {
    if (!token.empty()) {
        detectAlphabetErrors(token);
        int num = std::stoi(token);
        return num;
    }
    return 0;
}

std::string StringCalculator::replaceDelimiters(std::string input) {
    if (input.substr(0, 2) == "//") {
        char delimiter = input[2];
        input = input.substr(4);
        std::replace(input.begin(), input.end(), delimiter, ',');
    }
    std::replace(input.begin(), input.end(), '\n', ',');
    return input;
}

int StringCalculator::computeSumFromString(const std::string& input) {
    std::string processedInput = replaceDelimiters(input);
    int sum = 0;
    std::stringstream ss(processedInput);
    std::string token;
    while (std::getline(ss, token, ',')) {
        int num = handleWhitespaceAndConvert(token);
        if (num < 0) {
            negativeNumbers.push_back(num);
            hasNegativeNumbers = true;
        } else {
            sum += limitToThousand(num);
        }
    }
    validateNoNegatives();
    return sum;
}
