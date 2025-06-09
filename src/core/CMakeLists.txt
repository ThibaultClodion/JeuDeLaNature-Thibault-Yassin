add_library(lib_core Param.h 
"map/Map.h" "map/Map.cpp"
"map/Cell.h" "map/Cell.cpp" 
"map/Nature.h" "map/Nature.cpp" 
"map/Field.h" "map/Field.cpp"
"map/Home.h" "map/Home.cpp" 
"power/PowerManager.h" "power/PowerManager.cpp"
"power/Power.h" "power/Freeze.h" 
"power/Naturalize.h" "power/Earthquake.h" 
"power/SpreadLimit.h" "power/Sunlight.h" 
"power/Wind.h")

target_include_directories(lib_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib_core PUBLIC sfml-graphics sfml-audio)