#pragma once

/**
 * CliOps
 * Provides command line argument interfaces
 */

// std
#include <string>
#include <vector>


namespace tul {
    extern std::vector<std::string> globalArgs;

    void SetupArguments(int argc, char** argv);

    int CheckArgument(const std::string& name);
    std::string GetArgument(int index);

    std::string GetValue(const std::string& key);

}