#pragma once

/**
 * StringOps
 * Manages strings
 */

// std
#include <string>
#include <vector>
#include <cstdint>

namespace tul {

    std::vector<std::string> SplitString(const std::string& source, char delimeter);
    uint32_t HashString(const std::string& string);

}