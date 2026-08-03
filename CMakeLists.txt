cmake_minimum_required(VERSION 3.20)

project(Instantulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(Instantulator
    src/main.cpp

    src/app/public/find.cpp

    src/app/private/clean_input.cpp
    src/app/private/form_elements.cpp
    src/app/private/is_ordered.cpp
    src/app/private/calculate.cpp
    src/app/private/calculate_elements.cpp
)

target_include_directories(Instantulator PRIVATE
    src/app
)