#include "streamlog.h"
//#include <iterator>

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

    std::string StreamLog::trigger(std::string event_name) {
        auto fun = this->listeners[event_name];
        fun();
        return event_name;
    }

    std::string StreamLog::on(std::string listener_name, std::function<void(void)> handler) {
        this->listeners[listener_name] = handler;
        return listener_name;
    }
}
