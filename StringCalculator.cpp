#include "StringCalculator.h"
#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <string>

// Global variables for error handling
std::vector<int> negativeNumbers;
int negativeCount = 0;

// Custom exception class
class CustomException : public std::runtime_error {
public:
    CustomException(const std::string& message)
        : std::runtime_error(message) {}
};

// Check for alphabetical characters in the token
void validateForAlphabets(const std::string& token) {
    for(char ch : token) {
        if(std::isalpha(ch)) {
            std::string message = "Alphabetic characters are not permitted: ";
            throw CustomException(message);
        }
    }
}

// Handle negative numbers and throw an exception
void handleNegativeNumbers() {
    std::string message = "Negative numbers are not allowed: ";
    for (size_t i = 0; i < negativeNumbers.size(); ++i) {
        message += std::to_string(negativeNumbers[i]);
        if (i < negativeNumbers.size() - 1) {
            message += ", ";
        }
    }
    throw CustomException(message);
}

// Validate if the number is below a certain threshold
int StringCalculator::validateNumberThreshold(int number) {
    return (number >= 1000) ? 0 : number;
}

// Ensure the number is positive and process negative numbers
int StringCalculator::processPositiveNumber(int number) {
    if (number >= 0) {
        return validateNumberThreshold(number);
    } else {
        negativeNumbers.push_back(number);
        negativeCount++;
        return 0;
    }
}

// Format input string by replacing delimiters
std::string StringCalculator::formatStringForDelimiters(const std::string& input) {
    std::string formattedInput = input;
    if (formattedInput.substr(0, 2) == "//") {
        char delimiter = formattedInput[2];
        formattedInput = formattedInput.substr(4);
        std::replace(formattedInput.begin(), formattedInput.end(), delimiter, ',');
    }
    std::replace(formattedInput.begin(), formattedInput.end(), '\n', ',');
    return formattedInput;
}

// Handle whitespace and conversion errors
int StringCalculator::convertTokenToNumber(const std::string& token) {
    if (!token.empty()) {
        validateForAlphabets(token);
        return std::stoi(token);
    }
    return 0;
}

// Compute the sum of numbers in the input string
int StringCalculator::computeSum(const std::string& input) {
    std::string formattedInput = formatStringForDelimiters(input);
    int totalSum = 0;
    std::stringstream ss(formattedInput);
    std::string token;

    while (std::getline(ss, token, ',')) {
        int number = convertTokenToNumber(token);
        totalSum += processPositiveNumber(number);
    }

    if (negativeCount > 0) {
        handleNegativeNumbers();
    }

    return totalSum;
}
