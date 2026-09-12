#include "tul/DeskOps.hpp"

#if defined(_WIN32) || defined(_WIN64)
    #define TUL_WIN
    #include <windows.h>
    #include <shellapi.h>
#elif defined(__APPLE__) || defined(__linux__)
    #define TUL_POSIX
    #include <spawn.h>
    #include <sys/wait.h>
    extern char** environ;
#endif

/// @brief Opens the destination in it's default app
/// @param destination Destination (ex: "https://test.com" or "test.txt")
bool tul::OpenExternal(const std::string &destination)
{
    #ifdef TUL_WIN
    HINSTANCE result = ShellExecuteA(
        nullptr,
        "open",
        destination.c_str(),
        nullptr,
        nullptr,
        SW_SHOWNORMAL
    );
    return reinterpret_cast<intptr_t>(result) > 32;
    #elif defined(TUL_POSIX)

    pid_t pid;

    char* argv[] = {
        const_cast<char*>("open"),
        const_cast<char*>(destination.c_str())
        nullptr
    };

    int result = posix_spawnp(
        &pid,
        "open",
        nullptr,
        nullptr,
        argv,
        environ
    );

    if(result != 0) return false;

    int status;
    waitpid(pid, &status, 0);
    return WIFEXITED(status) && WEXITSTATUS(status) == 0;
    #endif

    return false;
}
