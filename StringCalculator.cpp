#include "StringCalculator.h"
#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>

namespace {
    std::vector<int> negativeNumbers;
    bool hasNegatives = false;

    class CustomException : public std::runtime_error {
    public:
        CustomException(const std::string& message)
            : std::runtime_error(message) {}
    };

    void checkForAlphabet(const std::string& token) {
        for (char ch : token) {
            if (std::isalpha(ch)) {
                throw CustomException("Alphabets are not allowed: " + token);
            }
        }
    }

    void validateNegatives() {
        if (hasNegatives) {
            std::string message = "Negatives are not allowed: ";
            for (size_t i = 0; i < negativeNumbers.size(); ++i) {
                message += std::to_string(negativeNumbers[i]);
                if (i < negativeNumbers.size() - 1) {
                    message += ", ";
                }
            }
            throw CustomException(message);
        }
    }
}

int StringCalculator::checkIfLessThanThousand(int num) {
    return (num >= 1000) ? 0 : num;
}

int StringCalculator::validateNonNegative(int num) {
    if (num < 0) {
        negativeNumbers.push_back(num);
        hasNegatives = true;
        return 0;
    }
    return checkIfLessThanThousand(num);
}

std::string StringCalculator::adjustDelimiters(std::string input) {
    if (input.rfind("//", 0) == 0) {
        char customDelimiter = input[2];
        input = input.substr(4);
        std::replace(input.begin(), input.end(), customDelimiter, ',');
    }
    std::replace(input.begin(), input.end(), '\n', ',');
    return input;
}

int StringCalculator::handleWhitespace(std::string token) {
    if (!token.empty()) {
        checkForAlphabet(token);
        return std::stoi(token);
    }
    return 0;
}

int StringCalculator::add(std::string input) {
    std::string adjustedInput = adjustDelimiters(input);
    int total = 0;
    std::stringstream ss(adjustedInput);
    std::string token;

    while (std::getline(ss, token, ',')) {
        int number = handleWhitespace(token);
        total += validateNonNegative(number);
    }

    validateNegatives();
    return total;
}
