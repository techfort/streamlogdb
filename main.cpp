#include <iostream>
#include "core/streamlog.h"
#include "core/event.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    cout << "Hello StreamLog" << endl;
    StreamLog::StreamLog log("MyLog");

    StreamLog::Event * event = new StreamLog::Event();
    event->id = "hello-stream-log";
    event->type = StreamLog::Event::Type::UPDATE;
    event->timestamp = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    rapidjson::Document * doc = new rapidjson::Document();
    doc->Parse("{\"name\":\"joe\", \"age\": 40}");
    event->data = doc;
    log.add(event);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc->Accept(writer);

    // testing lambdas and variable capture..
    int t = 0;
    log.on("test", [&t] () {
       cout << "Test event received " << ++t << endl;
    });

    log.trigger("test");

    cout << "Stringified data: " << buffer.GetString() << endl;
    return 0;
}

