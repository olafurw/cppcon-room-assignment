#ifndef CPPCON_ROOM_ASSIGNMENT_UTILS_H
#define CPPCON_ROOM_ASSIGNMENT_UTILS_H

#include <string>

namespace utils
{
    std::string
    FileToString(
        const std::string&  aFilename);

    void
    StringToFile(
        const std::string&  aFilename,
        const std::string&  aContent);
}

#endif
