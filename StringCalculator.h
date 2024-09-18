#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>

class StringCalculator
{
  public:
    int checkIfLessThanThousand(int num);
    int validateNonNegative(int num);

    std::string adjustDelimiters(std::string input);
    int handleWhitespace(std::string token);
    int add(std::string input);
};

#endif // STRINGCALCULATOR_H
