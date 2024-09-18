#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& input);

private:
    std::string extractDelimiter(const std::string& input);
    std::vector<std::string> splitNumbers(const std::string& input, const std::string& delimiter);
    std::vector<int> parseNumbers(const std::string& input);
    
    // New helper methods
    std::vector<int> collectNegatives(const std::vector<int>& numbers);
    void handleNegatives(const std::vector<int>& negatives);
};

#endif // STRING_CALCULATOR_H
