add_library(tul STATIC
    src/StringOps.cpp
    src/FileOps.cpp
    src/Error.cpp
)

target_include_directories(tul
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
