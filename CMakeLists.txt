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
add_subdirectory(src/main)
add_subdirectory(src/test)