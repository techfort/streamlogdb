#include "streamlog.h"

namespace StreamLog {
    StreamLog::StreamLog(std::string str_name) {
        this->name = str_name;
    }

    std::vector<Event *> StreamLog::getEvents() {
        return this->events;
    }

    Event * StreamLog::add(Event * event) {
        this->events.push_back(event);
        return event;
    }
}
