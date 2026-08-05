#include <string>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_stdlib.h>

#include "help_screen.h"

HelpScreen::HelpScreen(App &app, AppFsm &fsm)
{
    this->app = &app;
    this->fsm = &fsm;
}

void HelpScreen::build()
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
    
    const char* titleText = "INSTANTULATOR   |   HELP";
    ImGui::TextUnformatted(titleText);

    ImGui::SetCursorPosY(0);
    ImGui::SetCursorPosX((width - btnSize.x) * 0.95);
    if (ImGui::Button("<", btnSize)) {
        fsm->setState(AppState::Main);
    }

    ImGui::TextUnformatted("HOW TO USE: input arithmetics as a string.");
    ImGui::TextUnformatted("EXAMPLE:");

    std::string arithmeticExample = "2 + 46 - 2.76";
    ImGui::SetNextItemWidth(width * 0.9);
    ImGui::InputTextWithHint(
        "##ArithmeticExample",
        "",
        &arithmeticExample,
        ImGuiInputTextFlags_ReadOnly);

    ImGui::TextUnformatted("");
    ImGui::TextUnformatted("CURRENTLY SUPPORTED OPERATIONS:");
    ImGui::TextUnformatted("(+), (-), (*), (/), (^)");
    ImGui::TextUnformatted("");
    ImGui::TextUnformatted("Project by CookieJar187 (MIT License)");
    ImGui::TextUnformatted("Report bugs on:");

    std::string githubLink = "https://github.com/CookieJar187/instantulator.git";
    ImGui::SetNextItemWidth(width * 0.9);
    ImGui::InputTextWithHint(
        "##GithubLink",
        "",
        &githubLink,
        ImGuiInputTextFlags_ReadOnly);

    ImGui::End();
}