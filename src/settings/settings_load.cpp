#include <iostream>
#include <fstream>
#include <filesystem>

#include "settings.h"

bool Settings::load()
{
    if (!std::filesystem::exists("config.json"))
    {
        std::ofstream newFile("config.json");

        if (!newFile.is_open())
        {
            std::cerr << "error opening config.json\n";
            return false;
        }
        else
        {
            newFile << default_json;
            newFile.close();
        }
    }

    std::ifstream file("config.json");
    file >> config;

    return true;
}