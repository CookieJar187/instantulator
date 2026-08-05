#include <fstream>
#include <filesystem>

#include "settings.h"

bool Settings::save()
{
    std::ofstream file("config.json");

    if (!file.is_open())
    {
        std::cerr << "Could not open config.json\n";
        return false;
    }

    file << config.dump(4);

    if (!file)
    {
        std::cerr << "Could not write config.json\n";
        return false;
    }

    return true;
}