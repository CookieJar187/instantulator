#pragma once

#include "algorithm.h"
#include "app_fsm.h"

class MainScreen
{
public:
    MainScreen(Algorithm &app, AppFsm &fsm);
    void build();

private:
    Algorithm *app;
    AppFsm *fsm;

    std::string currInput = "";
    std::string currOutput = "";
};