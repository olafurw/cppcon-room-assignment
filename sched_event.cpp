#include "sched_event.h"

#include <iomanip>
#include <sstream>

TimePoint
StringToTimePoint(
    const std::string&  aTimeStr)
{
    std::stringstream ss(aTimeStr);
    std::tm tm = {};
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

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

    myEventStart = StringToTimePoint(myEventStartStr);
    myEventEnd = StringToTimePoint(myEventEndStr);
}

bool
SchedEvent::Overlaps(
    const SchedEvent& aSchedEvent) const
{
    return myEventStart >= aSchedEvent.myEventStart && myEventEnd <= aSchedEvent.myEventEnd;
}