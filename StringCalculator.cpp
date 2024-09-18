#include "StringCalculator.h"
#include <sstream>
#include <algorithm>
#include <iterator>

// Define the add method
int StringCalculator::add(const std::string& input) {
    if (input.empty()) return 0;

    std::string delimiter = extractDelimiter(input);
    std::vector<std::string> tokens = splitNumbers(input, delimiter);
    std::vector<int> numbers = parseTokens(tokens);

    std::vector<int> negatives = collectNegatives(numbers);
    handleNegatives(negatives);

    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

std::vector<int> StringCalculator::parseTokens(const std::vector<std::string>& tokens) {
    std::vector<int> numbers;
    for (const std::string& token : tokens) {
        int number = std::stoi(token);
        if (number < 0) {
            throw std::runtime_error("Negatives not allowed: " + std::to_string(number));
        }
        numbers.push_back(number);
    }
    return numbers;
}

void StringCalculator::handleNegatives(const std::vector<int>& negatives) {
    if (negatives.empty()) return;

    std::string errorMessage = buildErrorMessage(negatives);
    throw std::runtime_error(errorMessage);
}

std::string StringCalculator::buildErrorMessage(const std::vector<int>& negatives) {
    std::string errorMessage = "Negatives not allowed: ";
    for (int num : negatives) {
        errorMessage += std::to_string(num) + " ";
    }
    return errorMessage;
}

std::vector<int> StringCalculator::collectNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(negatives),
                 [](int number) { return number < 0; });
    return negatives;
}

std::string StringCalculator::extractDelimiter(const std::string& numbers) {
    // Extract delimiter logic
    // Dummy implementation
    return ",";
}

std::vector<std::string> StringCalculator::splitNumbers(const std::string& input, const std::string& delimiter) {
    // Split numbers logic
    // Dummy implementation
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(input);
    while (std::getline(tokenStream, token, delimiter[0])) {
        tokens.push_back(token);
    }
    return tokens;
}

void StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    // Check for negatives logic
    // Dummy implementation
}
