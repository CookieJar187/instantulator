#include "algorithm.h"

bool Algorithm::isOrdered(std::vector<std::optional<Element>> &elements)
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