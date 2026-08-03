#include <imgui.h>
#include <imgui_impl_glfw.h>

#include "main_screen.h"

MainScreen::MainScreen(AppFsm &fsm)
{
    this->fsm = &fsm;
}

void MainScreen::build() const
{
    static char inputBuffer[256] = "";
    static char outputBuffer[36] = "";

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

    ImGui::Begin("Main Menu", nullptr, flags);

    ImVec2 titleSize = ImVec2(160.0f, 20.0f);
    ImVec2 btnSize = ImVec2(20.0f, 20.0f);

    //ImGui::SetCursorPosY(height * 0.35f);
    
    const char* titleText = "INSTANTULATOR";
    ImGui::TextUnformatted(titleText);

    ImGui::SetCursorPosY(0);
    ImGui::SetCursorPosX((width - btnSize.x));
    if (ImGui::Button("?", btnSize)) {
        fsm->setState(AppState::Help);
    }

    ImGui::SetCursorPosY(0);
    ImGui::SetCursorPosX((width - btnSize.x * 2));
    if (ImGui::Button("Settings", btnSize)) {
        fsm->setState(AppState::Settings);
    }

    ImGui::SetCursorPosY(0);
    ImGui::SetCursorPosX((width - btnSize.x * 3));
    if (ImGui::Button("X", btnSize)) {
        fsm->setState(AppState::Quit);
    }

    ImGui::SetCursorPosY(height * 0.3);
    ImGui::SetNextItemWidth(width * 0.5);
    ImGui::InputTextWithHint(
        "##Input",
        "Input arithmetics...",
        inputBuffer,
        IM_ARRAYSIZE(inputBuffer));

    ImGui::SetCursorPosY(height * 0.3);
    ImGui::SetCursorPosX(width * 0.68);
    ImGui::SetNextItemWidth(width * 0.3);
    ImGui::InputTextWithHint(
        "##Output",
        "Result...",
        outputBuffer,
        IM_ARRAYSIZE(outputBuffer),
        ImGuiInputTextFlags_ReadOnly);

    ImGui::End();
}