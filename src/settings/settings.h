#pragma once

#include <iostream>
#include <string>
#include <array>
#include <optional>
#include <chrono>
#include <nlohmann/json.hpp>

class Settings
{
private:
    nlohmann::json config;

    std::string default_json = R"({
        "AlwaysOnTop" : false,
        "WindowBgColor" : {"x" : 0.06, "y" : 0.06, "z" : 0.06, "a" : 0.94},
        "TextColor" : {"x" : 1.0, "y" : 1.0, "z" : 1.0, "a" : 1.0},
        "CheckMarkColor" : {"x" : 0.26, "y" : 0.59, "z" : 0.98, "a" : 1.0}
    })";

public:
    bool load();
    bool save();

    bool getBool(const std::string &targetName) const;
    int getInt(const std::string &targetName) const;
    float getFloat(const std::string &targetName) const;
    std::array<float, 2> getFloat2(const std::string &targetName) const;
    std::array<float, 3> getFloat3(const std::string &targetName) const;
    std::array<float, 4> getFloat4(const std::string &targetName) const;

    void setBool(const std::string &targetName, bool value);
    void setInt(const std::string &targetName, int value);
    void setFloat(const std::string &targetName, float value);
    void setFloat2(const std::string &targetName, std::array<float, 2> &value);
    void setFloat3(const std::string &targetName, std::array<float, 3> &value);
    void setFloat4(const std::string &targetName, std::array<float, 4> &value);
};