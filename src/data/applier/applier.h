#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "data_types.h"
#include "runtime.h"

class Applier
{
public:
    Applier(Runtime &runtime);

    void setWindow(GLFWwindow *window);

    void applyWindowHints() const;
    void applyWindowAttribs() const;
    void applyImGui() const;

private:
    Runtime *runtime = nullptr;

    GLFWwindow *window = nullptr;

};