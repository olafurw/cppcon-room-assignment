#ifndef CPPCON_ROOM_ASSIGNMENT_SCHED_EVENT_H
#define CPPCON_ROOM_ASSIGNMENT_SCHED_EVENT_H

#include <string>
#include <chrono>
#include "json.hpp"

using TimePoint = std::chrono::system_clock::time_point;

struct SchedEvent
{
    std::string     myId = "";
    std::string     myName = "";
    std::string     mySpeakers = "";
    std::string     myEventStartStr = "";
    TimePoint       myEventStart{};
    std::string     myEventEndStr = "";
    TimePoint       myEventEnd{};
    int32_t         myGoers = 0;

    SchedEvent() = default;
    SchedEvent(
        const nlohmann::json& aJson);
};

#endif
