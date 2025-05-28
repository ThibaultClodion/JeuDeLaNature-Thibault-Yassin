add_executable(unitTests
    unitTests.cpp
)

target_link_libraries(unitTests
    GTest::gtest_main
    lib_core
    sfml-graphics
)

gtest_discover_tests(unitTests)