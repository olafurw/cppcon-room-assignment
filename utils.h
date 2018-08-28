#ifndef CPPCON_ROOM_ASSIGNMENT_UTILS_H
#define CPPCON_ROOM_ASSIGNMENT_UTILS_H

#include <string>

namespace utils
{
    std::string&
    LeftTrim(
        std::string& aStr);

    std::string&
    RightTrim(
        std::string& aStr);

    std::string
    Trim(
        const std::string& aStr);

    bool
    FileExists(
        const std::string&  aFilename);

    std::string
    FileToString(
        const std::string&  aFilename);

    bool
    StringToFile(
        const std::string&  aFilename,
        const std::string&  aContent);
}

#endif
