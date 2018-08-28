#include <stdio.h>
#include <iostream>

#include <string>
#include <optional>

#include "utils.h"
#include "http_init.h"
#include "http_get.h"
#include "json.hpp"
#include "flags.hpp"
#include "sched_event.h"

static const char* locSchedJsonFilename = "sched.json";
static const char* locApiKeyFilename = "api.key";

bool
UpdateSchedCache()
{
    const std::string apiKey = utils::Trim(utils::FileToString(locApiKeyFilename));
    if (apiKey.empty())
    {
        std::cout << "File: 'api.key', missing\n";
        return false;
    }

    HttpInit init;

    HttpGet get;
    const std::string url = "https://cppcon2018.sched.com/api/session/list?api_key=" + apiKey + "&format=json";
    const auto content = get.Get(url);
    if (!content)
    {
        std::cout << "Failure fetching sched content\n";
        return false;
    }

    const auto jsonContent = StringToJson(content.value());
    if (!jsonContent)
    {
        std::cout << "Failure parsing sched json\n";
        return false;
    }

    const bool writeResult = utils::StringToFile(locSchedJsonFilename, jsonContent.value().dump(4));
    if (!writeResult)
    {
        std::cout << "Failure writing sched json to " << locSchedJsonFilename << "\n";
        return false;
    }

    std::cout << "Wrote " << locSchedJsonFilename << "\n";

    return true;
}

int
main(
    int     aArgc,
    char**  aArgv)
{
    const flags::args args(aArgc, aArgv);
    const bool force = args.get<bool>("f", false);

    if (force
        || !utils::FileExists(locSchedJsonFilename))
    {
        if (!UpdateSchedCache())
        {
            std::cout << "Unable to update sched json file\n";
            return 1;
        }
    }

    const std::string schedContent = utils::FileToString(locSchedJsonFilename);
    const auto schedJson = utils::StringToJson(schedContent);
    if (!schedJson)
    {
        std::cout << "Unable to parse sched json file\n";
        return 1;
    }
    
    /*nlohmann::json jsonContent;
    
    try
    {
        jsonContent = nlohmann::json::parse(content.value());
    }
    catch(...)
    {
        return 1;
    }

    std::vector<SchedEvent> events;

    for(const nlohmann::json& event : jsonContent)
    {
        SchedEvent e;
        e.myName = event["name"];
        e.myGoers = std::stoi(event["goers"].get<std::string>());

        std::cout << e.myGoers << " " << e.myName << std::endl;
    }*/

    return 1;
}