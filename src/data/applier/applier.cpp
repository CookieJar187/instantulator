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

void Applier::setWindow(GLFWwindow *window)
{
    this->window = window;
}

void Applier::applyWindowHints() const
{
    bool alwaysOnTop = runtime->alwaysOnTop;
    glfwWindowHint(GLFW_FLOATING, (alwaysOnTop) ? GLFW_TRUE : GLFW_FALSE);
}

void Applier::applyWindowAttribs() const
{
    bool alwaysOnTop = runtime->alwaysOnTop;
    glfwSetWindowAttrib(window, GLFW_FLOATING, (alwaysOnTop) ? GLFW_TRUE : GLFW_FALSE);
}

void Applier::applyImGui() const
{
    Color3 windowBgColor = runtime->windowBgColor;
    Color3 textColor = runtime->textColor;
    Color3 checkMarkColor = runtime->checkMarkColor;
    Color3 frameBgColor = runtime->frameBgColor;
    Color3 buttonColor = runtime->buttonColor;
    
    ImGuiStyle &style = ImGui::GetStyle();

    style.Colors[ImGuiCol_WindowBg] = ImVec4(
        windowBgColor.x,
        windowBgColor.y,
        windowBgColor.z,
        0.94f
    );

    // Text
    style.Colors[ImGuiCol_Text] = ImVec4(
        textColor.x,
        textColor.y,
        textColor.z,
        1.0f
    );
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(
        textColor.x,
        textColor.y,
        textColor.z,
        0.5f
    );

    // Frame & Checkbox
    style.Colors[ImGuiCol_CheckMark] = ImVec4(
        checkMarkColor.x,
        checkMarkColor.y,
        checkMarkColor.z,
        1.0f
    );
    style.Colors[ImGuiCol_CheckboxSelectedBg] = ImVec4(
        frameBgColor.x,
        frameBgColor.y,
        frameBgColor.z,
        0.54f
    );
    style.Colors[ImGuiCol_FrameBg] = ImVec4(
        frameBgColor.x,
        frameBgColor.y,
        frameBgColor.z,
        0.54f
    );
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(
        frameBgColor.x,
        frameBgColor.y,
        frameBgColor.z,
        1.0f
    );
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(
        frameBgColor.x,
        frameBgColor.y,
        frameBgColor.z,
        0.2f
    );

    // Button
    style.Colors[ImGuiCol_Button] = ImVec4(
        buttonColor.x,
        buttonColor.y,
        buttonColor.z,
        0.40f
    );
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(
        buttonColor.x,
        buttonColor.y,
        buttonColor.z,
        1.0f
    );
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(
        buttonColor.x,
        buttonColor.y,
        buttonColor.z,
        0.20f
    );
}