#include "StringCalculator.h"
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cctype>

std::vector<int> negativeNumbers;
int negativeFlag = 0;

class CalculationException : public std::runtime_error {
public:
    CalculationException(const std::string& message)
        : std::runtime_error(message) {}
};

void checkForAlphabets(const std::string& token)
{
    for(char ch : token)
        if(std::isalpha(ch))
        {
            throw CalculationException("Alphabets are not allowed: " + token);
        }
}

void handleNegativeNumbers()
{
    std::string message = "Negative numbers not permitted: ";
    for (size_t i = 0; i < negativeNumbers.size(); ++i) 
    {
        message += std::to_string(negativeNumbers[i]);
        if (i < negativeNumbers.size() - 1) 
        {
            message += ", ";
        }
    }
    throw CalculationException(message);
}

int StringCalculator::limitToMaxValue(int number)
{
    return (number >= 1000) ? 0 : number;
}

int StringCalculator::processNumber(int number)
{
    if (number >= 0)
        return limitToMaxValue(number);
    else
    {
        negativeNumbers.push_back(number);
        negativeFlag++;
        return 0;
    }
}

std::string StringCalculator::adjustStringDelimiters(const std::string& input)
{
    std::string modifiedInput = input;
    if (input.substr(0, 2) == "//") 
    {
        char customDelimiter = input[2];
        modifiedInput = input.substr(4);
        std::replace(modifiedInput.begin(), modifiedInput.end(), customDelimiter, ',');
    }
    std::replace(modifiedInput.begin(), modifiedInput.end(), '\n', ',');
    return modifiedInput;
}

int StringCalculator::handleTokenConversion(const std::string& token)
{
    if (!token.empty()) 
    {
        checkForAlphabets(token);
        return std::stoi(token);
    }
    return 0;
}

int StringCalculator::computeSumFromString(const std::string& input)
{
    std::string adjustedInput = adjustStringDelimiters(input);
    int totalSum = 0;
    std::stringstream ss(adjustedInput);
    std::string token;
    while (std::getline(ss, token, ','))
    {
        int number = handleTokenConversion(token);
        totalSum += processNumber(number);
    }
    if (negativeFlag > 0)
        handleNegativeNumbers();
    return totalSum;
}
