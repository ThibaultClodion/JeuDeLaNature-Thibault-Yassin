add_library(lib_game
  Game.h Game.cpp
  UIManager.h UIManager.cpp
  MainMenu.h MainMenu.cpp)

target_include_directories(lib_game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib_game
  PUBLIC
    lib_core
    sfml-graphics
    sfml-window
    sfml-system
    ImGui-SFML
)