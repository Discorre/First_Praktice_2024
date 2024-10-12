# CMake generated Testfile for 
# Source directory: C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_fetch_content
# Build directory: C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-build/test/cmake_fetch_content
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cmake_fetch_content_configure "D:/Toolbox Library/CLion/bin/cmake/win/x64/bin/cmake.exe" "-G" "Ninja" "-DCMAKE_CXX_COMPILER=D:/Toolbox Library/CLion/bin/mingw/bin/g++.exe" "-Dnlohmann_json_source=C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src" "C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_fetch_content/project")
set_tests_properties(cmake_fetch_content_configure PROPERTIES  FIXTURES_SETUP "cmake_fetch_content" LABELS "git_required" _BACKTRACE_TRIPLES "C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_fetch_content/CMakeLists.txt;2;add_test;C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_fetch_content/CMakeLists.txt;0;")
add_test(cmake_fetch_content_build "D:/Toolbox Library/CLion/bin/cmake/win/x64/bin/cmake.exe" "--build" ".")
set_tests_properties(cmake_fetch_content_build PROPERTIES  FIXTURES_REQUIRED "cmake_fetch_content" LABELS "git_required" _BACKTRACE_TRIPLES "C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_fetch_content/CMakeLists.txt;9;add_test;C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_fetch_content/CMakeLists.txt;0;")
