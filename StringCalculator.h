#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <vector>
#include <string>

class StringCalculator {
public:
    int add(const std::string& input);
    std::vector<int> parseNumbers(const std::string& numbers);
    void handleNegatives(const std::vector<int>& negatives);
    std::vector<int> collectNegatives(const std::vector<int>& numbers);

private:
    std::string extractDelimiter(const std::string& numbers);
    std::vector<std::string> splitNumbers(const std::string& input, const std::string& delimiter);
    void checkForNegatives(const std::vector<int>& numbers);
    std::vector<int> parseTokens(const std::vector<std::string>& tokens);
    std::string buildErrorMessage(const std::vector<int>& negatives);
};

#endif // STRING_CALCULATOR_H
