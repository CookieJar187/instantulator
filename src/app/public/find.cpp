#include "app.h"

std::string App::find(std::string &input)
{
    std::string clean = cleanInput(input);
    
    std::vector<std::optional<Element>>
        elements = formElements(clean);
    
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
            {
                stringResult = stringResult.substr(0, dotPos);
                std::cout << "action\n";
            }

            return stringResult;
        }
    }

    return "";
}