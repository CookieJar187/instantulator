#pragma once

#include "app.h"
#include "app_fsm.h"
#include "data.h"

class SettingsScreen
{
public:
    SettingsScreen(App &app, AppFsm &fsm, Data &data);
    void build();

private:
    App *app;
    AppFsm *fsm;
    Data *data;

    bool currAlwaysOnTop;
    Color3 currWindowBgColor;
    Color3 currTextColor;
    Color3 currCheckMarkColor;
    Color3 currFrameBgColor;
    Color3 currButtonColor;
};