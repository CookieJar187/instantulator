#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "app.h"
#include "app_fsm.h"
#include "settings.h"

#include "main_screen.h"
#include "help_screen.h"
#include "settings_screen.h"

class UiManager
{   
private:
    App *app;
    AppFsm *fsm;
    Settings *settings;

    MainScreen *mainScreen;
    HelpScreen *helpScreen;
    SettingsScreen *settingsScreen;

public:
    int init(GLFWwindow* window, App *app, AppFsm* fsm, Settings* settings);
    void buildUi();
    void drawUi();
    void destroyUi();
};