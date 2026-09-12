#include "tul/ErrorOps.hpp"

#if defined(_WIN32) || defined(_WIN64)
    #define TUL_WIN
    #include <windows.h>
#endif

// std
#include <iostream>

/// @brief Prints out a simple message
/// @param message Message
void tul::Print(const std::vector<std::string> &message)
{
    for(const auto& content : message) {
        std::cout << content;
    }
}

/// @brief (Windows Only) Displays a message box
/// @note On non-windows systems prints out the message as red and bold
/// @param message Message
void tul::Alert(const std::vector<std::string> &message)
{
    #ifdef TUL_WIN
    const char* buffer = std::string(message.begin(), message.end()).c_str();
    MessageBoxA(
        nullptr,
        buffer,
        "ALERT",
        MB_OK | MB_ICONEXCLAMATION
    );
    #else
    Print({BOLD, RED});
    Print(message);
    Print({RESET, NEWLINE});
    #endif
}

/// @brief (Windows Only) Displays a message box and quits the application
/// @note On non-windows systems prints out the message as red and bold
/// @param message Message
void tul::FatalError(const std::vector<std::string> &message)
{
    #ifdef TUL_WIN
    const char* buffer = std::string(message.begin(), message.end()).c_str();
    MessageBoxA(
        nullptr,
        buffer,
        "ALERT",
        MB_OK | MB_ICONEXCLAMATION
    );
    #else
    Print({BOLD, RED});
    Print(message);
    Print({RESET, NEWLINE});
    #endif
    std::exit(EXIT_FAILURE);
}
