cmake_minimum_required(VERSION 3.26)

project(JeuDeLaNature VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

if(WIN32)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

set(BUILD_SHARED_LIBS FALSE)

# SFML
include(FetchContent)
FetchContent_Declare(sfml
  URL https://github.com/SFML/SFML/archive/refs/tags/3.0.1.tar.gz
)
FetchContent_MakeAvailable(sfml)

# ImGui and ImGui-SFML
FetchContent_Declare( imgui
  URL https://github.com/ocornut/imgui/archive/refs/tags/v1.91.9.tar.gz
)
FetchContent_MakeAvailable(imgui)

FetchContent_Declare( imgui-sfml
  URL https://github.com/SFML/imgui-sfml/archive/refs/tags/v3.0.tar.gz
)

set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" OFF)
FetchContent_MakeAvailable(imgui-sfml)

# GoogleTest
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.tar.gz
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

# Sous-dossiers
add_subdirectory(src/core)
add_subdirectory(src/game)
add_subdirectory(src/main)
add_subdirectory(src/test)