#ifndef STREAMLOG_H
#define STREAMLOG_H

#include "event.h"
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;

namespace StreamLog {

    class StreamLog
    {
    public:
        StreamLog(string);
        vector<Event *> getEvents();
        Event * add(Event *);
        string trigger(string);
        string on(string, function<void (void)>);

    private:
        string name;
        vector<Event *> events;
        map< string, function<void (void)> > listeners;
    };
}

#endif // STREAMLOG_H
