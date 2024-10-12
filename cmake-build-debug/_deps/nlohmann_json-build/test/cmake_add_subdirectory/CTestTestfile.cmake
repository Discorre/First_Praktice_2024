# CMake generated Testfile for 
# Source directory: C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_add_subdirectory
# Build directory: C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-build/test/cmake_add_subdirectory
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cmake_add_subdirectory_configure "D:/Toolbox Library/CLion/bin/cmake/win/x64/bin/cmake.exe" "-G" "Ninja" "-DCMAKE_CXX_COMPILER=D:/Toolbox Library/CLion/bin/mingw/bin/g++.exe" "-Dnlohmann_json_source=C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src" "C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_add_subdirectory/project")
set_tests_properties(cmake_add_subdirectory_configure PROPERTIES  FIXTURES_SETUP "cmake_add_subdirectory" _BACKTRACE_TRIPLES "C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_add_subdirectory/CMakeLists.txt;1;add_test;C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_add_subdirectory/CMakeLists.txt;0;")
add_test(cmake_add_subdirectory_build "D:/Toolbox Library/CLion/bin/cmake/win/x64/bin/cmake.exe" "--build" ".")
set_tests_properties(cmake_add_subdirectory_build PROPERTIES  FIXTURES_REQUIRED "cmake_add_subdirectory" _BACKTRACE_TRIPLES "C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_add_subdirectory/CMakeLists.txt;8;add_test;C:/Users/Dom/CLionProjects/First_Praktice_2024/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_add_subdirectory/CMakeLists.txt;0;")
