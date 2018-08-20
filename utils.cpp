#include "utils.h"

#include <fstream>

namespace utils
{
    std::string
    FileToString(
        const std::string&  aFilename)
    {
        std::ifstream in(aFilename, std::ios::in | std::ios::binary);
        std::string content;

        in.seekg(0, std::ios::end);
        if (in.tellg() < 1)
        {
            return content;
        }

        content.resize(in.tellg());
        in.seekg(0, std::ios::beg);

        in.read(&content[0], content.size());
        in.close();

        return content;
    }

    void
    StringToFile(
        const std::string&  aFilename,
        const std::string&  aContent)
    {
        std::ofstream file(aFilename);
        file << aContent;
    }
}