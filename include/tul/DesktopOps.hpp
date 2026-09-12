#pragma once

/**
 * DesktopOps
 * Handles system dependent process tasks (like opening files in the default app)
 */

// std
#include <string>

namespace tul {

    bool OpenExternal(const std::string& destination);

}