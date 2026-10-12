#include "tul/StringOps.hpp"
#include "tul/FileOps.hpp"
#include <stdexcept>

json tul::localizationFile;
std::string tul::currentLocale = "";
json tul::localeObject;

/// @brief Splits a string into a vector
/// @param source Source string
/// @param delimeter Delimeter character
/// @return Vector of split text
std::vector<std::string> tul::SplitString(const std::string &source, char delimeter)
{
    std::vector<std::string> result;
    std::string acc;
    
    for(const char c : source) {
        if(c == delimeter) {
            result.emplace_back(acc);
            acc = "";
        } else acc += c;
    }

    result.emplace_back(acc);
    return result;
}

/// @brief Does FNV-1a hash to a string
/// @param string String
/// @return Hashed string
uint32_t tul::HashString(const std::string &string)
{
    uint32_t hash = 2166136261u;

    for (unsigned char c : string)
    {
        hash ^= c;
        hash *= 16777619u;
    }

    return hash;
}

/// @brief Loads a JSON file containing locale data
/// @param path JSON file path
/// @throws std::runtime_error If the file cannot be read or parsed
void tul::SetLocalizationData(const std::filesystem::path& path) {
    try {
        auto data = json::parse(ReadFile(path));

        if (!data.is_object()) {
            throw std::runtime_error("Localization root must be a JSON object");
        }

        localizationFile = std::move(data);
    }
    catch (const json::parse_error& e) {
        throw std::runtime_error(
            "Failed to parse localization file '" +
            path.string() + "': " + e.what()
        );
    }
}

/// @brief Sets the current locale
/// @param locale Identifier (example: en-US, ru-RU)
void tul::SetLocale(const std::string& locale) {
    if(!localizationFile.contains(locale))
        throw std::runtime_error("No locale exists: " + locale);

    currentLocale = locale;
    localeObject = localizationFile[locale];
}

/// @brief Gets a value based on a key
/// @param key Key
/// @return Localized text
std::string tul::GetLocaleString(const std::string& key) {
    if(!localeObject.contains(key))
        throw std::runtime_error("Locale: " + currentLocale + " does not contain key: " + key);
    
    return localeObject[key].get<std::string>();
}