#include "settings.h"

bool Settings::getBool(const std::string &targetName) const
{
    bool value = config[targetName].get<bool>();
    return value;
}

int Settings::getInt(const std::string &targetName) const
{
    int value = config[targetName].get<int>();
    return value;
}

float Settings::getFloat(const std::string &targetName) const
{
    float value = config[targetName].get<float>();
    return value;
}

std::array<float, 2> Settings::getFloat2(const std::string &targetName) const
{
    std::array<float, 2> arr{
        config[targetName]["x"].get<float>(),
        config[targetName]["y"].get<float>()
    };

    return arr;
}

std::array<float, 3> Settings::getFloat3(const std::string &targetName) const
{
    std::array<float, 3> arr{
        config[targetName]["x"].get<float>(),
        config[targetName]["y"].get<float>(),
        config[targetName]["z"].get<float>()
    };

    return arr;
}

std::array<float, 4> Settings::getFloat4(const std::string &targetName) const
{
    std::array<float, 4> arr{
        config[targetName]["x"].get<float>(),
        config[targetName]["y"].get<float>(),
        config[targetName]["z"].get<float>(),
        config[targetName]["a"].get<float>()
    };

    return arr;
}