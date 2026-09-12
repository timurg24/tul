#pragma once

/**
 * ErrorOps
 * Provides error logging functions
 */

// std
#include <string>
#include <vector>

namespace tul {

    #define RED     "\033[31m"
    #define GREEN   "\033[32m"
    #define YELLOW  "\033[33m"
    #define BOLD    "\033[1m"
    #define RESET   "\033[0m"

    #define RETURN  "\r"
    #define TAB     "\t"
    #define NEWLINE "\n"

    void Print(const std::vector<std::string>& message);
    void Alert(const std::vector<std::string>& message);
    [[noreturn]] void FatalError(const std::vector<std::string>& message);
}

