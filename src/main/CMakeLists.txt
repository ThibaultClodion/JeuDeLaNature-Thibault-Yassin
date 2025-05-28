add_executable(main
    main.cpp
)

target_link_libraries(main PUBLIC lib_core sfml-graphics)

# Copy resources
file(GLOB RESOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/resources/*.*)

add_custom_target(copy-resources ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources
    COMMENT "Copying resource files to build directory"
)
add_dependencies(main copy-resources)