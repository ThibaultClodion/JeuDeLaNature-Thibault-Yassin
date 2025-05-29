add_library(lib_core
    Circle.cpp Circle.h
 Param.h)

target_include_directories(lib_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib_core PUBLIC sfml-graphics)