#include "utils.h"

#include <fstream>
#include <algorithm>

namespace utils
{
    std::string&
    LeftTrim(
        std::string& aStr)
    {
        aStr.erase(aStr.begin(), std::find_if(aStr.begin(), aStr.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return aStr;
    }

    std::string&
    RightTrim(
        std::string& aStr)
    {
        aStr.erase(std::find_if(aStr.rbegin(), aStr.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), aStr.end());
        return aStr;
    }

    std::string
    Trim(
        const std::string& aStr)
    {
        std::string tmp_str = aStr;
        return LeftTrim(RightTrim(tmp_str));
    }

    bool
    FileExists(
        const std::string&  aFilename)
    {
        std::ifstream in(aFilename, std::ios::in | std::ios::binary);
        return in.good();
    }

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

    bool
    StringToFile(
        const std::string&  aFilename,
        const std::string&  aContent)
    {
        std::ofstream file(aFilename);
        if (!file.good())
        {
            return false;
        }

        file << aContent;

        return file.good();
    }

    std::optional<nlohmann::json>
    StringToJson(
        const std::string&  aContent)
    {
        try
        {
            return nlohmann::json::parse(aContent);
        }
        catch(...)
        {
            return {};
        }
    }
}