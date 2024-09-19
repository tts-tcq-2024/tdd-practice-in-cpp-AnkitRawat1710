#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>

std::vector<int> StringCalculator::parseNumbers(const std::string& numbers, const char delimiter) {
    std::vector<int> parsedNumbers;
    std::istringstream iss(numbers);
    std::string token;

    while (std::getline(iss, token, delimiter)) {
        int number = std::stoi(token);
        if (number <= 1000) {
            parsedNumbers.push_back(number);
        }
    }

    return parsedNumbers;
}

void StringCalculator::validateNumbers(const std::vector<int>& numbers) {
    std::string negativeNumbers;
    for (int number : numbers) {
        if (number < 0) {
            negativeNumbers += std::to_string(number) + ",";
        }
    }

    if (!negativeNumbers.empty()) {
        throw std::runtime_error("Negatives not allowed: " + negativeNumbers.substr(0, negativeNumbers.length() - 1));
    }
}

int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum;
}

int StringCalculator::add(const std::string& numbers) {
    char delimiter = ',';
    if (numbers.starts_with("//")) {
        delimiter = numbers[2];
        numbers = numbers.substr(4);
    }

    std::vector<int> parsedNumbers = parseNumbers(numbers, delimiter);
    validateNumbers(parsedNumbers);
    return sumNumbers(parsedNumbers);
}
