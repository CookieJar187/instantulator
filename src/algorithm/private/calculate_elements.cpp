#include "algorithm.h"

void Algorithm::calculateElements(
    std::vector<std::optional<Element>> &elements
)
{
    std::optional<Element *> prevNum = std::nullopt;
    std::optional<Element *> prevOperand = std::nullopt;

    int elementsRemaining = 0;
    do{
        elementsRemaining = 0;

        for (int i = 0; i < elements.size(); ++i)
        {
            Element *curr;

            if (!elements[i].has_value())
                continue;
            elementsRemaining++;

            curr = &elements[i].value();

            // Calculate
            if (prevNum.has_value()
                && prevOperand.has_value()
                && curr->elementType == ElementType::Number
            )
            calculate(elements, *prevNum.value(), *prevOperand.value(), *curr);

            // Set elements
            if (curr->elementType == ElementType::Number)
                prevNum = curr;
            else if (curr->elementType == ElementType::Operator)
                prevOperand = curr;
        }

        prevNum = std::nullopt;
        prevOperand = std::nullopt;

    } while (elementsRemaining > 2);
}