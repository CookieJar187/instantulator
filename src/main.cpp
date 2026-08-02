#include <iostream>
#include <string>
#include <vector>
#include <optional>

#include <utility>
#include <algorithm>

// 0-9 = 48-57

enum class ElementType
{
    Number,
    Operator
};

struct Element
{
    std::string string;
    ElementType elementType;
    unsigned __int64 index;
};

std::string cleanInput(const std::string &input)
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

std::vector<std::optional<Element>>
    formElements(const std::string &clean)
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

bool isOrdered(std::vector<std::optional<Element>> &elements)
{
    ElementType prevType = ElementType::Operator;

    for (int i = 0; i < elements.size(); ++i)
    {
        ElementType currType = elements[i].value().elementType;

        if (currType == prevType)
            return false;

        prevType = currType;
    }

    return true;
}
/*
void calculate(std::vector<std::optional<Element>> &elements)
{
    std::optional<Element *> prevNum = std::nullopt;
    std::optional<Element *> prevOperand = std::nullopt;

    for (int i = 0; i < elements.size(); ++i)
    {
        Element *curr;

        if (!elements[i].has_value())
            continue;
        curr = &elements[i].value();

        // Calculate
        if (prevNum.has_value()
            && prevOperand.has_value()
            && curr->elementType == ElementType::Number
        )
        {
            std::string operandString = prevOperand.value()->string;
            if (operandString == "+")
            {
                elements[i] = std::stof("12");
            }
        }

        // Set elements
        if (curr->elementType == ElementType::Number)
            prevNum = curr;
        else if (curr->elementType == ElementType::Operator)
            prevOperand = curr;
    }
}
*/
int main()
{
    std::string input = "32*2.5+sgfgn22";

    std::string clean = cleanInput(input);
    
    std::vector<std::optional<Element>>
        elements = formElements(clean);

    if (!isOrdered(elements))
    {
        throw "Elements out of order";
        return -1;
    }

    std::cout << "Original\n";
    for (int i = 0; i < elements.size(); ++i)
    {
        bool kaka = true;
        if (elements[i].value().elementType == ElementType::Operator)
            kaka = false;
        std::cout << elements[i].value().string << " (" << kaka << ")\n";
    }

    return 0;
}