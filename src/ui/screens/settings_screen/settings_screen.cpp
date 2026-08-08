#include <string>
#include <algorithm>
#include <iterator>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_stdlib.h>

#include "settings_screen.h"

SettingsScreen::SettingsScreen(Algorithm &app, AppFsm &fsm, Data &data)
{
    this->app = &app;
    this->fsm = &fsm;
    this->data = &data;

    currAlwaysOnTop = this->data->runtime.alwaysOnTop;
    currWindowBgColor = this->data->runtime.windowBgColor;
    currTextColor = this->data->runtime.textColor;
    currCheckMarkColor = this->data->runtime.checkMarkColor;
    currFrameBgColor = this->data->runtime.frameBgColor;
    currButtonColor = this->data->runtime.buttonColor;
}

void SettingsScreen::build()
{
    ImGuiIO& io = ImGui::GetIO();
    float width = io.DisplaySize.x;
    float height = io.DisplaySize.y;

    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(width, height));

    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoBringToFrontOnFocus;

    ImGui::Begin("Help Screen", nullptr, flags);

    ImVec2 titleSize = ImVec2(160.0f, 20.0f);
    ImVec2 btnSize = ImVec2(20.0f, 20.0f);

    //ImGui::SetCursorPosY(height * 0.35f);
    
    const char* titleText = "INSTANTULATOR   |   SETTINGS";
    ImGui::TextUnformatted(titleText);

    ImGui::SetCursorPosY(0);
    ImGui::SetCursorPosX((width - btnSize.x) * 0.95);
    if (ImGui::Button("<", btnSize)) {
        fsm->setState(AppState::Main);
    }

    ImGui::TextUnformatted("\nWINDOW");

    static bool alwaysOnTop = currAlwaysOnTop;
    if (ImGui::Checkbox("Always On Top", &alwaysOnTop))
    {
        data->runtime.alwaysOnTop = alwaysOnTop;
        data->applier.applyWindowAttribs();
    }

    ImGui::TextUnformatted("\nTHEME");

    static float windowBgColor[3] = {
        currWindowBgColor.x,
        currWindowBgColor.y,
        currWindowBgColor.z
    };
    ImGui::PushItemWidth(100);
    if (ImGui::ColorPicker3(
        "WindowBg Color",
        windowBgColor
    ))
    {
        data->runtime.windowBgColor = Color3{
            windowBgColor[0],
            windowBgColor[1],
            windowBgColor[2]
        };
        data->applier.applyImGui();
    }

    static float textColor[3] = {
        currTextColor.x,
        currTextColor.y,
        currTextColor.z
    };
    ImGui::PushItemWidth(100);
    if (ImGui::ColorPicker3(
        "Text Color",
        textColor
    ))
    {
        data->runtime.textColor = Color3{
            textColor[0],
            textColor[1],
            textColor[2]
        };
        data->applier.applyImGui();
    }

    static float checkMarkColor[3] = {
        currCheckMarkColor.x,
        currCheckMarkColor.y,
        currCheckMarkColor.z
    };
    ImGui::PushItemWidth(100);
    if (ImGui::ColorPicker3(
        "CheckMark Color",
        checkMarkColor
    ))
    {
        data->runtime.checkMarkColor = Color3{
            checkMarkColor[0],
            checkMarkColor[1],
            checkMarkColor[2]
        };
        data->applier.applyImGui();
    }

    static float frameBgColor[3] = {
        currFrameBgColor.x,
        currFrameBgColor.y,
        currFrameBgColor.z
    };
    ImGui::PushItemWidth(100);
    if (ImGui::ColorPicker3(
        "FrameBg Color",
        frameBgColor
    ))
    {
        data->runtime.frameBgColor = Color3{
            frameBgColor[0],
            frameBgColor[1],
            frameBgColor[2]
        };
        data->applier.applyImGui();
    }

    static float buttonColor[3] = {
        currButtonColor.x,
        currButtonColor.y,
        currButtonColor.z
    };
    ImGui::PushItemWidth(100);
    if (ImGui::ColorPicker3(
        "Button Color",
        buttonColor
    ))
    {
        data->runtime.buttonColor = Color3{
            buttonColor[0],
            buttonColor[1],
            buttonColor[2]
        };
        data->applier.applyImGui();
    }

    ImGui::End();
}