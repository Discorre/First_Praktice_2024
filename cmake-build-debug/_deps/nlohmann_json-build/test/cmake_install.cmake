# Install script for directory: C:/Users/Dom/CLionProjects/untitled1/cmake-build-debug/_deps/nlohmann_json-src/test

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/untitled1")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "D:/Toolbox Library/CLion/bin/mingw/bin/objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Dom/CLionProjects/untitled1/cmake-build-debug/_deps/nlohmann_json-build/test/cmake_import/cmake_install.cmake")
  include("C:/Users/Dom/CLionProjects/untitled1/cmake-build-debug/_deps/nlohmann_json-build/test/cmake_import_minver/cmake_install.cmake")
  include("C:/Users/Dom/CLionProjects/untitled1/cmake-build-debug/_deps/nlohmann_json-build/test/cmake_add_subdirectory/cmake_install.cmake")
  include("C:/Users/Dom/CLionProjects/untitled1/cmake-build-debug/_deps/nlohmann_json-build/test/cmake_fetch_content/cmake_install.cmake")
  include("C:/Users/Dom/CLionProjects/untitled1/cmake-build-debug/_deps/nlohmann_json-build/test/cmake_target_include_directories/cmake_install.cmake")

endif()

