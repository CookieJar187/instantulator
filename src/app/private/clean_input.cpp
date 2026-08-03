#include "app.h"

std::string App::cleanInput(const std::string &input)
{
    std::string clean;

    int exprLength = 0;
    for (int i = 0; i < input.length(); ++i)
    {
        char currChar = input.at(i);

        if (
            currChar >= 48 && currChar <= 57
            || currChar == '.'
            || currChar == '+' || currChar == '-'
            || currChar == '*' || currChar == '/'
            || currChar == '^'
        )
        {
            exprLength++;
        }
        else if (exprLength > 0)
        {
            std::string temp = input.substr(i - exprLength, exprLength);
            clean += temp;
            exprLength = 0;
        }
    }

    if (exprLength > 0)
    {
        std::string temp = input.substr(input.length() - exprLength, exprLength);
        clean += temp;
    }

    return clean;
}