#include <iostream>
#include "core/streamlog.h"
#include "core/event.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"

using namespace std;

int main()
{
    cout << "Hello StreamLog" << endl;
    StreamLog::StreamLog log("MyLog");

    StreamLog::Event * event = new StreamLog::Event();
    event->id = "hello-stream-log";
    rapidjson::Document * doc = new rapidjson::Document();
    doc->Parse("{\"name\":\"joe\", \"age\": 40}");
    event->data = doc;
    log.add(event);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc->Accept(writer);

    log.on("test", [] () {
       cout << "Test event received" << endl;
    });

    log.trigger("test");

    cout << "Stringified data: " << buffer.GetString() << endl;
    return 0;
}

