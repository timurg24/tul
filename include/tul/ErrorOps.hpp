#pragma once

/**
 * ErrorOps
 * Provides error logging functions
 */

// std
#include <string>
#include <vector>

namespace tul {

    // ANSI colors / formatting
    inline constexpr const char* RED    = "\033[31m";
    inline constexpr const char* GREEN  = "\033[32m";
    inline constexpr const char* YELLOW = "\033[33m";
    inline constexpr const char* BOLD   = "\033[1m";
    inline constexpr const char* RESET  = "\033[0m";

    // Formatting characters
    inline constexpr const char* RETURN  = "\r";
    inline constexpr const char* TAB     = "\t";
    inline constexpr const char* NEWLINE = "\n";

    void Print(const std::vector<std::string>& message);
    void Alert(const std::vector<std::string>& message);
    [[noreturn]] void FatalError(const std::vector<std::string>& message);
}

