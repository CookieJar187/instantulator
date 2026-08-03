#pragma once

#include "app_fsm.h"

class MainScreen
{
public:
    MainScreen(AppFsm &fsm);
    void build() const;

private:
    AppFsm *fsm;
};