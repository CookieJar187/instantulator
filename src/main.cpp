#include <iostream>
#include <string>

#include "app.h"

int main()
{
    App app{};

    std::cout << "Please input the equation\n";
    std::string input;
    std::cin >> input;

    std::string result = app.find(input);
    std::cout << result << std::endl;

    return 0;
}