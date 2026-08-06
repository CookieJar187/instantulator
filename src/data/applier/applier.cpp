#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "applier.h"

Applier::Applier(Runtime &runtime)
{
    this->runtime = &runtime;
}

void Applier::applySettings()
{
    std::cout << "changed made\n";

    // glfw
    {
        bool alwaysOnTop = runtime->alwaysOnTop;

        if (alwaysOnTop)
        {
            glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
            std::cout << "always on\n";
        }
        else
        {
            glfwWindowHint(GLFW_FLOATING, GLFW_FALSE);
            std::cout << "always off\n";
        }
            
    }

    // ImGui
    {
        Color4 windowBgColor = runtime->windowBgColor;
        Color4 textColor = runtime->textColor;
        Color4 checkMarkColor = runtime->checkMarkColor;

        ImGuiStyle &style = ImGui::GetStyle();

        style.Colors[ImGuiCol_WindowBg] = ImVec4(
            windowBgColor.x,
            windowBgColor.y,
            windowBgColor.z,
            windowBgColor.a
        );

        style.Colors[ImGuiCol_Text] = ImVec4(
            textColor.x,
            textColor.y,
            textColor.z,
            textColor.a
        );

        style.Colors[ImGuiCol_CheckMark] = ImVec4(
            checkMarkColor.x,
            checkMarkColor.y,
            checkMarkColor.z,
            checkMarkColor.a
        );

    }

}