#include "StringCalculator.h"
#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <string>

// Custom exception class for error handling
class CalculationException : public std::runtime_error {
std::vector<int> negatives;
int flag = 0;
class Exception : public std::runtime_error {
public:
    explicit CalculationException(const std::string& message)
    Exception(const std::string& message)
        : std::runtime_error(message) {}
};

// Global variables to track negative numbers
std::vector<int> negativeNumbers;
bool hasNegativeNumbers = false;
void detectAlphabetErrors(const std::string& token) {
    for (char ch : token) {
        if (isalpha(ch)) {
            throw CalculationException("Alphabets not allowed: " + token);
void alphabet_error(std::string token)
{
    for (char ch : token)
        if (isalpha(ch))
        {
            std::string message = "Alphabets not allowed: ";
            throw Exception(message);
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
void throw_error()
{
    std::string message = "Negatives not allowed: ";
    for (int i = 0; i < negatives.size(); ++i)
    {
        message += std::to_string(negatives[i]);
        if (i < negatives.size() - 1)
        {
            message += ", ";
        }
        throw CalculationException(message);
    }
    throw Exception(message);
}

int StringCalculator::limitToThousand(int num) {
    return (num >= 1000) ? 0 : num;
int StringCalculator::check_for_less_than_thousand(int num)
{
    if (num >= 1000)
        return 0;
    else
        return num;
}

int StringCalculator::handleWhitespaceAndConvert(const std::string& token) {
    if (!token.empty()) {
        detectAlphabetErrors(token);
        int num = std::stoi(token);
        return num;
int StringCalculator::get_positive_number(int num)
{
    int digit = 0;
    if (num >= 0)
        digit = check_for_less_than_thousand(num);
    else
    {
        negatives.push_back(num);
        flag++;
    }
    return 0;
    return digit;
}

std::string StringCalculator::replaceDelimiters(std::string input) {
    if (input.substr(0, 2) == "//") {
std::string StringCalculator::Process_String_for_delimiters(std::string input)
{
    if (input.substr(0, 2) == "//")
    {
        char delimiter = input[2];
        input = input.substr(4);
        std::replace(input.begin(), input.end(), delimiter, ',');
    return input;
}

int StringCalculator::computeSumFromString(const std::string& input) {
    std::string processedInput = replaceDelimiters(input);
int StringCalculator::exception_handling_for_whitespce(std::string token)
{
    if (!token.empty())
    {  // Check if the token is not empty
        alphabet_error(token);
        int num = std::stoi(token);  // Convert to integer
        return num;
    }
    return 0;
}
int StringCalculator::add(std::string input)
{
    std::string processed_input = Process_String_for_delimiters(input);
    int sum = 0;
    std::stringstream ss(processedInput);
    std::stringstream ss(processed_input);
    std::string token;
    while (std::getline(ss, token, ',')) {
        int num = handleWhitespaceAndConvert(token);
        if (num < 0) {
            negativeNumbers.push_back(num);
            hasNegativeNumbers = true;
        } else {
            sum += limitToThousand(num);
        }
    while (std::getline(ss, token, ','))
    {
        int num = exception_handling_for_whitespce(token);
        int addition = get_positive_number(num);
        sum += addition;
    }
    validateNoNegatives();
    if (flag > 0)
        throw_error();
    return sum;
}
