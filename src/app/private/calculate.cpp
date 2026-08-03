#include "app.h"

void App::calculate(
    std::vector<std::optional<Element>> &elements,
    Element &elemNum1,
    Element &elemOperand,
    Element &elemNum2
)
{
    float num1 = std::stof(elemNum1.string);
    float num2 = std::stof(elemNum2.string);

    float result;

    std::string operandString = elemOperand.string;
    if (operandString == "+")
        result = num1 + num2;
    else if (operandString == "-")
        result = num1 - num2;
    else if (operandString == "*")
        result = num1 * num2;
    else if (operandString == "/")
        result = num1 / num2;
    else if (operandString == "^")
        result = num1 / num2;
    else
    {
        std::cout << "ERROR!\n";
        throw "Unsuported operation";
        return;
    }
    
    elements[elemNum2.index].value().string = std::to_string(result);
    elements[elemNum1.index] = std::nullopt;
    elements[elemOperand.index] = std::nullopt;
}