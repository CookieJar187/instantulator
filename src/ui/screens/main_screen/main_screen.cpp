#include <string>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_stdlib.h>

#include "main_screen.h"

MainScreen::MainScreen(Algorithm &app, AppFsm &fsm)
{
    this->app = &app;
    this->fsm = &fsm;
}

void MainScreen::build()
{
    static std::string inputString = "";

    //strcpy(inputBuffer, currInput.c_str());
    //strcpy(outputBuffer, currOutput.c_str());

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
        &inputString
    );

    if (inputString != currInput)
    {
        std::optional<std::string> output = app->find(inputString);
        if (!output.has_value())
            currOutput = "";
        else
            currOutput = output.value();
            
        currInput = inputString;
    }

    ImGui::SetCursorPosY(height * 0.3);
    ImGui::SetCursorPosX(width * 0.68);
    ImGui::SetNextItemWidth(width * 0.3);
    ImGui::InputTextWithHint(
        "##Output",
        "Result...",
        &currOutput,
        ImGuiInputTextFlags_ReadOnly);

    ImGui::End();
}