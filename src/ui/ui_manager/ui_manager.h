#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "app_fsm.h"
#include "main_screen.h"

class UiManager
{   
private:
    AppFsm *fsm;

    MainScreen *mainScreen;

public:
    int init(GLFWwindow* window, AppFsm* fsm);
    void buildUi();
    void drawUi();
    void destroyUi();
};