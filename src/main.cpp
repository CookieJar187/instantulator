#include <iostream>
#include <string>
#include <vector>

// 0-9 = 48-57

struct Bind
{
    Bind(
        std::string &_elem1,
        std::string &_operand,
        std::string &_elem2
    ) :
    element1(&_elem1),
    operand(&_operand),
    element2(&_elem2)
    {}

    std::string *element1;
    std::string *operand;
    std::string *element2;
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

std::vector<std::string> separateElements(const std::string &clean)
{
    std::vector<std::string> elements;

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
                std::string temp = clean.substr(i - exprLength, exprLength);
                elements.push_back(temp);
                exprLength = 0;
            }

            std::string temp = clean.substr(i, 1);
            elements.push_back(temp);
        }
        else if (exprLength > 0)
        {
            std::string temp = clean.substr(i - exprLength, exprLength);
            elements.push_back(temp);
            exprLength = 0;
        }
    }

    if (exprLength > 0)
    {
        std::string temp = clean.substr(clean.length() - exprLength, exprLength);
        elements.push_back(temp);
    }

    return elements;
}

std::vector<Bind> bindElements(std::vector<std::string> &elements)
{
    std::vector<Bind> binds;

    for (int i = 0; i < elements.size(); i+=2)
    {
        if (i < 2)
            continue;
        
        Bind bind(
            elements[i - 2],
            elements[i - 1],
            elements[i]);

        binds.push_back(bind);
    }

    return binds;
}

int main()
{
    std::string input = "32/2298.21+sgfgn22";

    std::string clean = cleanInput(input);
    std::vector<std::string> elements = separateElements(clean);
    std::vector<Bind> binds = bindElements(elements);

    std::cout << "\nBinds: \n";
    for (auto &bind : binds)
    {
        std::cout << *bind.element1 << std::endl;
        std::cout << *bind.operand << std::endl;
        std::cout << *bind.element2 << std::endl << std::endl;
    }
    
    return 0;
}