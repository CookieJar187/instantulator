cmake_minimum_required(VERSION 3.20)

project(Instantulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(Instantulator
    src/main.cpp

    src/app/public/find.cpp

    src/app/private/clean_input.cpp
    src/app/private/form_elements.cpp
    src/app/private/is_ordered.cpp
    src/app/private/calculate.cpp
    src/app/private/calculate_elements.cpp

    src/app_fsm/app_fsm.cpp

    src/ui/ui_manager/ui_manager.cpp
    src/ui/screens/main_screen/main_screen.cpp
    src/ui/screens/help_screen/help_screen.cpp
    src/ui/screens/settings_screen/settings_screen.cpp

    src/data/storage/storage.cpp
    src/data/applier/applier.cpp
)

target_include_directories(Instantulator PRIVATE
    src/app

    src/app_fsm

    src/ui/ui_manager
    src/ui/screens/main_screen
    src/ui/screens/help_screen
    src/ui/screens/settings_screen

    src/data
    src/data/runtime
    src/data/storage
    src/data/applier
)

target_link_libraries(Instantulator PRIVATE
    glfw
    glad::glad
    imgui::imgui
    nlohmann_json::nlohmann_json
)