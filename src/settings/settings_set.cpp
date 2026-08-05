#include "settings.h"

void Settings::setBool(
    const std::string &targetName,
    bool value)
{
    config[targetName] = value;
}

void Settings::setInt(
    const std::string &targetName,
    int value)
{
    config[targetName] = value;
}

void Settings::setFloat(
    const std::string &targetName,
    float value)
{
    config[targetName] = value;
}

void Settings::setFloat2(
    const std::string &targetName,
    std::array<float, 2> &value)
{
    config[targetName] = {
        {"x", value[0]},
        {"y", value[1]}
    };
}

void Settings::setFloat3(
    const std::string &targetName,
    std::array<float, 3> &value)
{
    config[targetName] = {
        {"x", value[0]},
        {"y", value[1]},
        {"z", value[2]}
    };
}

void Settings::setFloat4(
    const std::string &targetName,
    std::array<float, 4> &value)
{
    config[targetName] = {
        {"x", value[0]},
        {"y", value[1]},
        {"z", value[2]},
        {"a", value[3]}
    };
}