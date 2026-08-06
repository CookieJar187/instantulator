#include <string>
#include <algorithm>
#include <iterator>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_stdlib.h>

#include "settings_screen.h"

SettingsScreen::SettingsScreen(App &app, AppFsm &fsm)
{
    this->app = &app;
    this->fsm = &fsm;
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

    ImGui::TextUnformatted("\nTHEME");

    static float windowBgColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    ImGui::PushItemWidth(100);
    ImGui::ColorPicker4(
        "WindowBg Color",
        windowBgColor
    );

    static float textColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    ImGui::PushItemWidth(100);
    ImGui::ColorPicker4(
        "Text Color",
        textColor
    );

    static float checkMarkColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    ImGui::PushItemWidth(100);
    ImGui::ColorPicker4(
        "CheckMark Color",
        checkMarkColor
    );

    ImGui::End();
}