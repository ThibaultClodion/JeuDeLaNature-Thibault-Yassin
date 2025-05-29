add_library(lib_core Param.h 
Map.h Map.cpp
Cell.h Cell.cpp 
Nature.h 
Field.h
)

target_include_directories(lib_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib_core PUBLIC sfml-graphics)