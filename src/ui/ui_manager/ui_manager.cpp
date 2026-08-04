#include <iostream>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "ui_manager.h"

int UiManager::init(GLFWwindow* window, App *app, AppFsm* fsm)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    if (!ImGui_ImplGlfw_InitForOpenGL(window, true)) {
        std::cerr << "Failed to initialize ImgGui GLFW backend" << std::endl;
        return 1;
    }
    if (!ImGui_ImplOpenGL3_Init("#version 330")) {
        std::cerr << "Failed to initialize ImgGui OpenGL backend" << std::endl;
        return 1;
    }

    UiManager::app = app;
    UiManager::fsm = fsm;
    UiManager::mainScreen = new MainScreen(*app, *fsm);
    UiManager::helpScreen = new HelpScreen(*app, *fsm);
    
    return 0;
}

void UiManager::buildUi()
{
    // Begin ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGuiStyle &style = ImGui::GetStyle();
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.0f);

    // Build ui
    if (fsm->isState(AppState::Main))
        UiManager::mainScreen->build();
    else if (fsm->isState(AppState::Help))
        UiManager::helpScreen->build();
    else
        std::cerr << "UiManager: unsuported state" << std::endl;
}

void UiManager::drawUi()
{
    // Draw ui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UiManager::destroyUi()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}