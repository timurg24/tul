#pragma once

/**
 * ErrorOps
 * Provides error logging functions
 */

// std
#include <string>

namespace tul {
    void Print(const char* fmt, ...);
    void Alert(const char* fmt, ...);
    [[noreturn]] void FatalError(const char* fmt, ...);
}

