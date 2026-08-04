#pragma once

#include "app.h"
#include "app_fsm.h"

class HelpScreen
{
public:
    HelpScreen(App &app, AppFsm &fsm);
    void build();

private:
    App *app;
    AppFsm *fsm;

    std::string currInput = "";
    std::string currOutput = "";
};