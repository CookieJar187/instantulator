#pragma once

#include "algorithm.h"
#include "app_fsm.h"

class HelpScreen
{
public:
    HelpScreen(Algorithm &app, AppFsm &fsm);
    void build();

private:
    Algorithm *app;
    AppFsm *fsm;

    std::string currInput = "";
    std::string currOutput = "";
};