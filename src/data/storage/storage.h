#pragma once

#include <nlohmann/json.hpp>

#include "runtime.h"

class Storage
{
private:
    Runtime *runtime = nullptr;

    nlohmann::json config;

    std::string default_json = R"({
        "AlwaysOnTop" : false,
        "WindowBgColor" : {"x" : 0.06, "y" : 0.06, "z" : 0.06, "a" : 0.94},
        "TextColor" : {"x" : 1.0, "y" : 1.0, "z" : 1.0, "a" : 1.0},
        "CheckMarkColor" : {"x" : 0.26, "y" : 0.59, "z" : 0.98, "a" : 1.0}
    })";

    void runtimeToConfig();
    void configToRuntime();

public:
    Storage(Runtime &runtime);

    bool load();
    bool save();
};