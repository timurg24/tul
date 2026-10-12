#pragma once

/**
 * StringOps
 * Manages strings
 */

// std
#include <string>
#include <vector>
#include <cstdint>

#include "thirdparty/json.hpp"

using json = nlohmann::json;

namespace tul {

    std::vector<std::string> SplitString(const std::string& source, char delimeter);
    uint32_t HashString(const std::string& string);

    // localization
    extern json localizationFile;
    extern std::string currentLocale;
    extern json localeObject;
    void SetLocalizationData(const std::filesystem::path& path);
    void SetLocale(const std::string& locale);
    std::string GetLocaleString(const std::string& key);
}