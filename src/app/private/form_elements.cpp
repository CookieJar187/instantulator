#include "app.h"

std::vector<std::optional<App::Element>>
    App::formElements(const std::string &clean)
{
    std::vector<std::optional<Element>> elements;

    int exprLength = 0;
    for (int i = 0; i < clean.length(); ++i)
    {
        char currChar = clean.at(i);

        if (currChar >= 48 && currChar <= 57 || currChar == '.')
        {
            exprLength++;
        }
        else if (
            currChar == '+' || currChar == '-'
            || currChar == '*' || currChar == '/'
            || currChar == '^'
        )
        {
            if (exprLength > 0)
            {
                std::string string = clean.substr(i - exprLength, exprLength);
                Element elem{string, ElementType::Number, elements.size()};
                elements.push_back(elem);
                exprLength = 0;
            }

            std::string string = clean.substr(i, 1);
            Element elem{string, ElementType::Operator, elements.size()};
            elements.push_back(elem);
        }
        else if (exprLength > 0)
        {
            std::string string = clean.substr(i - exprLength, exprLength);
            Element elem{string, ElementType::Number, elements.size()};
            elements.push_back(elem);
            exprLength = 0;
        }
    }

    if (exprLength > 0)
    {
        std::string string = clean.substr(clean.length() - exprLength, exprLength);
        Element elem{string, ElementType::Number, elements.size()};
        elements.push_back(elem);
    }

    return elements;
}