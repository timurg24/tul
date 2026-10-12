cmake_minimum_required(VERSION 3.15)

# Only declare the project when built standalone, so add_subdirectory() keeps the parent's project
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(tul LANGUAGES CXX)
endif()

add_library(tul STATIC
    src/CliOps.cpp
    src/ErrorOps.cpp
    src/FileOps.cpp
    src/StringOps.cpp
)

target_compile_features(tul PUBLIC cxx_std_17)

target_include_directories(tul
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
