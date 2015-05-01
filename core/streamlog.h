#ifndef STREAMLOG_H
#define STREAMLOG_H

#include "event.h"
#include <vector>
#include <string>

namespace StreamLog {

    class StreamLog
    {
    public:
        StreamLog(std::string);
        std::vector<Event *> getEvents();
        Event * add(Event *);
    private:
        std::string name;
        std::vector<Event *> events;
    };
}

#endif // STREAMLOG_H
