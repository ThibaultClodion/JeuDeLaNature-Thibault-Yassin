add_test([=[Test1.Test]=]  [==[C:/Users/darkz/Desktop/TSP/Year 2/C++/JeuDeLaNature-Thibault-Yassin/out/build/x64-Debug/src/test/unitTests.exe]==] [==[--gtest_filter=Test1.Test]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Test1.Test]=]  PROPERTIES WORKING_DIRECTORY [==[C:/Users/darkz/Desktop/TSP/Year 2/C++/JeuDeLaNature-Thibault-Yassin/out/build/x64-Debug/src/test]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  unitTests_TESTS Test1.Test)
