#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

// Utility function to split a string by a specified delimiter
std::vector<std::string> StringCalculator::splitString(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = input.find(delimiter);
    
    while (end != std::string::npos) {
        tokens.push_back(input.substr(start, end - start));
        start = end + delimiter.length();
        end = input.find(delimiter, start);
    }
    tokens.push_back(input.substr(start));
    return tokens;
}

// Helper function to extract custom delimiter if specified in the format "//[delimiter]\n"
std::string StringCalculator::getDelimiter(const std::string& numbers) {
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find('\n');
        return numbers.substr(2, delimiterEnd - 2);
    }
    return ",|\n";  // Default delimiter is either comma or newline
}

// Helper function to get the section containing the actual numbers to be processed
std::string StringCalculator::getNumberSection(const std::string& numbers) {
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find('\n');
        return numbers.substr(delimiterEnd + 1);
    }
    return numbers;
}

// Helper function to parse and convert string numbers into integers, handles exceptions
std::vector<int> StringCalculator::parseNumbers(const std::string& numbers, const std::string& delimiter) {
    std::vector<std::string> tokens = splitString(numbers, delimiter);
    std::vector<int> numList;
    std::vector<int> negatives;

    for (const std::string& token : tokens) {
        if (!token.empty()) {
            int num = std::stoi(token);
            if (num < 0) {
                negatives.push_back(num);
            } else if (num <= 1000) {
                numList.push_back(num);
            }
        }
    }

    // Throw exception if negative numbers are found
    if (!negatives.empty()) {
        std::string errorMsg = "Negatives not allowed: ";
        for (int neg : negatives) {
            errorMsg += std::to_string(neg) + " ";
        }
        throw std::runtime_error(errorMsg);
    }

    return numList;
}

// Main 'add' method implementation
int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiter = getDelimiter(numbers);
    std::string numSection = getNumberSection(numbers);
    std::vector<int> numList = parseNumbers(numSection, delimiter);

    int sum = 0;
    for (int num : numList) {
        sum += num;
    }

    return sum;
}


