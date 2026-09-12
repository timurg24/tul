#pragma once

/**
 * FileOps
 * Handles files
 */

// std
#include <string>
#include <filesystem>

namespace tul {

    std::string ReadFile(const std::filesystem::path& path);

}