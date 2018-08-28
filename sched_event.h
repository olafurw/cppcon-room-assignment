#ifndef CPPCON_ROOM_ASSIGNMENT_SCHED_EVENT_H
#define CPPCON_ROOM_ASSIGNMENT_SCHED_EVENT_H

#include <string>
#include "json.hpp"

struct SchedEvent
{
    std::string     myId = "";
    std::string     myName = "";
    std::string     mySpeakers = "";
    std::string     myEventStartStr = "";
    std::string     myEventEndStr = "";
    int32_t         myGoers = 0;

    SchedEvent() = default;
    SchedEvent(
        const nlohmann::json& aJson);
};

#endif
