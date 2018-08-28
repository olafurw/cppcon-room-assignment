#include "sched_event.h"

SchedEvent::SchedEvent(
    const nlohmann::json& aEventJson)
{
    myId = aEventJson["id"].get<std::string>();
    myName = aEventJson["name"].get<std::string>();
    if (aEventJson.count("speakers"))
    {
        mySpeakers = aEventJson["speakers"].get<std::string>();
    }
    myEventStartStr = aEventJson["event_start"].get<std::string>();
    myEventEndStr = aEventJson["event_end"].get<std::string>();
    myGoers = std::stoi(aEventJson["goers"].get<std::string>());
}