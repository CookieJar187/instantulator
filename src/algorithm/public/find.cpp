#include "algorithm.h"

std::optional<std::string> Algorithm::find(std::string &input)
{
    std::optional<std::string> clean = cleanInput(input);
    if (!clean.has_value())
        return std::nullopt;
    
    std::vector<std::optional<Element>>
        elements = formElements(clean.value());
    
    if (!isOrdered(elements))
        throw "Elements out of order";
    
    calculateElements(elements);
    
    for (auto &elem : elements)
    {
        if (!elem.has_value())
            continue;

        if (elem.value().elementType == ElementType::Number)
        {
            std::string stringResult = elem.value().string;

            int dotPos = stringResult.find(".000");
            if (dotPos != std::string::npos)
                stringResult = stringResult.substr(0, dotPos);

            return stringResult;
        }
    }

    return "";
}