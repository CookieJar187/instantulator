#pragma once

#include "app.h"
#include "app_fsm.h"

class SettingsScreen
{
public:
    SettingsScreen(App &app, AppFsm &fsm);
    void build();

private:
    App *app;
    AppFsm *fsm;

    float currWindowBgColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    float currTextColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    float currCheckMarkColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
};