add_library(tul STATIC
    src/CliOps.cpp
    src/ErrorOps.cpp
    src/FileOps.cpp
    src/StringOps.cpp
)

target_include_directories(tul
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
