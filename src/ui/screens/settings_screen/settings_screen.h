#pragma once

#include "app.h"
#include "app_fsm.h"
#include "settings.h"

class SettingsScreen
{
public:
    SettingsScreen(App &app, AppFsm &fsm, Settings &settings);
    void build();

private:
    App *app;
    AppFsm *fsm;
    Settings *settings;

    float currWindowBgColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    float currTextColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    float currCheckMarkColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
};