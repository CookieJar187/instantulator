#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <optional>

class App
{
public:

    std::string find(std::string &input);

private:
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

    std::string cleanInput(const std::string &input);
    std::vector<std::optional<Element>> formElements(const std::string &clean);
    bool isOrdered(std::vector<std::optional<Element>> &elements);

    void calculate(
        std::vector<std::optional<Element>> &elements,
        Element &elemNum1,
        Element &elemOperand,
        Element &elemNum2
    );

    void calculateElements(
        std::vector<std::optional<Element>> &elements
    );
};