#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "app.h"
#include "app_fsm.h"
#include "ui_manager.h"

int main()
{
    /*
    App app{};

    std::cout << "Please input the equation\n";
    std::string input;
    std::cin >> input;

    std::string result = app.find(input);
    std::cout << result << std::endl;
    */

    App app;
    AppFsm fsm;
    UiManager uiManager;

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return 1;
    }

    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(400, 100, "Instantulator", nullptr, nullptr);

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
    uiManager.init(window, &fsm);

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
    uiManager.destroyUi();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}