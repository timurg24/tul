#pragma once
#include <string>
#include <filesystem>

namespace tul {

    std::string ReadFile(const std::filesystem::path& path);

}