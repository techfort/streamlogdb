#ifndef EVENT_H
#define EVENT_H

#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include <string>
#include <chrono>

namespace StreamLog {
    class Event
    {
    public:
        Event();
        enum Type {
            INSERT=0x1337, UPDATE=0x1338, DELETE=0x1339, REJECT=0x1340
        };
        rapidjson::Document * data;
        Type type;
        std::string id;
        std::chrono::milliseconds timestamp;
    };
}
#endif // EVENT_H
