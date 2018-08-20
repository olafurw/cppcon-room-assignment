#include <stdio.h>
#include <iostream>

#include <string>
#include <optional>

#include "utils.h"
#include "http_init.h"
#include "http_get.h"
#include "json.hpp"
#include "sched_event.h"

int main()
{
    const std::string apiKey = utils::FileToString("api.key");
    if (apiKey.empty())
    {
        std::cout << "File: 'api.key', missing\n";
        return 1;
    }

    HttpInit init;

    HttpGet get;
    const auto content = get.Get("https://cppcon2018.sched.com/api/session/list?api_key=" + apiKey + "&format=json");
    if (!content)
    {
        return 1;
    }
    
    nlohmann::json jsonContent;
    
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
    }

    return 1;
}