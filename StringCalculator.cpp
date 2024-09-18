#include "StringCalculator.h"
#include <sstream>
#include <algorithm>
#include <iterator>

std::vector<int> StringCalculator::parseNumbers(const std::string& numbers) {
    std::string delimiter = extractDelimiter(numbers);
    std::vector<std::string> tokens = splitNumbers(numbers, delimiter);
    std::vector<int> parsedNumbers = parseTokens(tokens);

    checkForNegatives(parsedNumbers);
    return parsedNumbers;
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
