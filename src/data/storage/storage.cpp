#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "storage.h"

Storage::Storage(Runtime &runtime)
{
    this->runtime = &runtime;
}

void Storage::runtimeToConfig()
{
    config["AlwaysOnTop"] = runtime->alwaysOnTop;
    
    config["WindowBgColor"]["x"] = runtime->windowBgColor.x;
    config["WindowBgColor"]["y"] = runtime->windowBgColor.y;
    config["WindowBgColor"]["z"] = runtime->windowBgColor.z;
    config["WindowBgColor"]["a"] = runtime->windowBgColor.a;

    config["TextColor"]["x"] = runtime->textColor.x;
    config["TextColor"]["y"] = runtime->textColor.y;
    config["TextColor"]["z"] = runtime->textColor.z;
    config["TextColor"]["a"] = runtime->textColor.a;

    config["CheckMarkColor"]["x"] = runtime->checkMarkColor.x;
    config["CheckMarkColor"]["y"] = runtime->checkMarkColor.y;
    config["CheckMarkColor"]["z"] = runtime->checkMarkColor.z;
    config["CheckMarkColor"]["a"] = runtime->checkMarkColor.a;
}

void Storage::configToRuntime()
{
    runtime->alwaysOnTop = config["AlwaysOnTop"];
    
    runtime->windowBgColor.x = config["WindowBgColor"]["x"];
    runtime->windowBgColor.y = config["WindowBgColor"]["y"];
    runtime->windowBgColor.z = config["WindowBgColor"]["z"];
    runtime->windowBgColor.a = config["WindowBgColor"]["a"];

    runtime->textColor.x = config["TextColor"]["x"];
    runtime->textColor.y = config["TextColor"]["y"];
    runtime->textColor.z = config["TextColor"]["z"];
    runtime->textColor.a = config["TextColor"]["a"];

    runtime->checkMarkColor.x = config["CheckMarkColor"]["x"];
    runtime->checkMarkColor.y = config["CheckMarkColor"]["y"];
    runtime->checkMarkColor.z = config["CheckMarkColor"]["z"];
    runtime->checkMarkColor.a = config["CheckMarkColor"]["a"];
}

bool Storage::load()
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

    configToRuntime();

    return true;
}

bool Storage::save()
{
    runtimeToConfig();

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