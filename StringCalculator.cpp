// StringCalculator.cpp

#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>
#include <regex>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    // Extract numbers based on the delimiter
    std::vector<int> extractedNumbers = extractNumbers(numbers, ",");
    
    // Sum the extracted numbers
    int sum = 0;
    for (int num : extractedNumbers) {
        if (num < 0) {
            throw std::runtime_error("negatives not allowed");
        }
        if (num <= 1000) {
            sum += num;
        }
    }

    return sum;
}

std::vector<int> StringCalculator::extractNumbers(const std::string& numbers, const std::string& delimiter) {
    std::regex regex("\\d+");
    std::smatch match;
    std::vector<int> extractedNumbers;

    std::string numbersCopy = numbers;
    std::string::size_type pos = 0;
    while ((pos = numbersCopy.find(delimiter)) != std::string::npos) {
        std::string token = numbersCopy.substr(0, pos);
        while (std::regex_search(token, match, regex)) {
            extractedNumbers.push_back(std::stoi(match.str()));
            token = match.suffix().str();
        }
        numbersCopy.erase(0, pos + delimiter.length());
    }

    while (std::regex_search(numbersCopy, match, regex)) {
        extractedNumbers.push_back(std::stoi(match.str()));
        numbersCopy = match.suffix().str();
    }

    return extractedNumbers;
}
