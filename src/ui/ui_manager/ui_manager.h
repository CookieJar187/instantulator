#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "app.h"
#include "app_fsm.h"
#include "data.h"

#include "main_screen.h"
#include "help_screen.h"
#include "settings_screen.h"

class UiManager
{   
private:
    App *app;
    AppFsm *fsm;
    Data *data;

    MainScreen *mainScreen;
    HelpScreen *helpScreen;
    SettingsScreen *settingsScreen;

public:
    int init(GLFWwindow* window, App *app, AppFsm* fsm, Data* data);
    void buildUi();
    void drawUi();
    void destroyUi();
};