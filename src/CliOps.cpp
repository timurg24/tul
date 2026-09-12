#include "tul/CliOps.hpp"

// std
#include <stdexcept>

// global define
std::vector<std::string> tul::globalArgs;

/// @brief Sets up the arguments to be used by other functions
/// @param argc Argument count
/// @param argv Argument data
void tul::SetupArguments(int argc, char **argv)
{
    globalArgs.resize(argc);
    for(int i = 0; i < argc; ++i) {
        globalArgs[i] = argv[i];
    }
}

/// @brief Checks if argument exists, then returns the index if it does
/// @param name Argument name
/// @return Index (-1 if not found)
int tul::CheckArgument(const std::string &name)
{
    for(int i = 0; i < globalArgs.size(); i++) {
        if(globalArgs[i] == name) return i;
    }
    return -1;
}

/// @brief Returns the string argument at index
/// @param index Argument index
/// @throws out_of_range If index is out of range
/// @return String
std::string tul::GetArgument(int index)
{
    if(index < 0 || static_cast<std::size_t>(index) >= globalArgs.size()) 
        throw std::out_of_range("Attempted to read out of bounds argument: " + std::to_string(index));
    return globalArgs[index];
}

/// @brief Keys a value based on a key (argument example: --language=english)
/// @param key Key (without the --)
/// @return Value (or "" when not found)
std::string tul::GetValue(const std::string &key)
{
    std::string fullKey = "--" + key;
    for(const auto& arg : globalArgs) {
        if(arg.rfind(fullKey + "=", 0) == 0) {
            return arg.substr(fullKey.size() + 1);
        }
    }
    return "";
}
