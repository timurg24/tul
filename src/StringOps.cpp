#include "tul/StringOps.hpp"

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
