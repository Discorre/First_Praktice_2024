cmake_minimum_required(VERSION 3.29)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.9.1  # Укажите нужную версию
)

FetchContent_MakeAvailable(nlohmann_json)

add_executable(untitled1 main.cpp
        Database.cpp
        Database.h
        Table.cpp
        Table.h
        QueryProcessor.cpp
        QueryProcessor.h)

# Подключение библиотеки nlohmann/json к вашему проекту
target_link_libraries(untitled1 PRIVATE nlohmann_json::nlohmann_json)