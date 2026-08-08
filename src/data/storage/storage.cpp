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

    config["TextColor"]["x"] = runtime->textColor.x;
    config["TextColor"]["y"] = runtime->textColor.y;
    config["TextColor"]["z"] = runtime->textColor.z;

    config["CheckMarkColor"]["x"] = runtime->checkMarkColor.x;
    config["CheckMarkColor"]["y"] = runtime->checkMarkColor.y;
    config["CheckMarkColor"]["z"] = runtime->checkMarkColor.z;

    config["FrameBgColor"]["x"] = runtime->frameBgColor.x;
    config["FrameBgColor"]["y"] = runtime->frameBgColor.y;
    config["FrameBgColor"]["z"] = runtime->frameBgColor.z;

    config["ButtonColor"]["x"] = runtime->buttonColor.x;
    config["ButtonColor"]["y"] = runtime->buttonColor.y;
    config["ButtonColor"]["z"] = runtime->buttonColor.z;
}

void Storage::configToRuntime()
{
    runtime->alwaysOnTop = config["AlwaysOnTop"];
    
    runtime->windowBgColor.x = config["WindowBgColor"]["x"];
    runtime->windowBgColor.y = config["WindowBgColor"]["y"];
    runtime->windowBgColor.z = config["WindowBgColor"]["z"];

    runtime->textColor.x = config["TextColor"]["x"];
    runtime->textColor.y = config["TextColor"]["y"];
    runtime->textColor.z = config["TextColor"]["z"];

    runtime->checkMarkColor.x = config["CheckMarkColor"]["x"];
    runtime->checkMarkColor.y = config["CheckMarkColor"]["y"];
    runtime->checkMarkColor.z = config["CheckMarkColor"]["z"];

    runtime->frameBgColor.x = config["FrameBgColor"]["x"];
    runtime->frameBgColor.y = config["FrameBgColor"]["y"];
    runtime->frameBgColor.z = config["FrameBgColor"]["z"];

    runtime->buttonColor.x = config["ButtonColor"]["x"];
    runtime->buttonColor.y = config["ButtonColor"]["y"];
    runtime->buttonColor.z = config["ButtonColor"]["z"];
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