#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <nlohmann/json.hpp>

#include "app.h"
#include "app_fsm.h"
#include "ui_manager.h"
#include "data.h"

int main()
{
    App app;
    AppFsm fsm;
    UiManager uiManager;
    Data data;
    data.storage.load();

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return 1;
    }

    data.applier.applyWindowHints();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(400, 100, "Instantulator", nullptr, nullptr);
    data.applier.setWindow(window);

    if (!window)
    {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cerr << "Failed to inialize GLAD\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    // Setup
    uiManager.init(window, &app, &fsm, &data);
    data.applier.applyImGui();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        uiManager.buildUi();

        glClear(GL_COLOR_BUFFER_BIT);

        uiManager.drawUi();
        glfwSwapBuffers(window);

        if (fsm.getState() == AppState::Quit)
            break;
    }
    data.storage.save();

    uiManager.destroyUi();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}