#include "NixAlarm.hpp"
#include <thread>
#include <chrono>
#include <stdlib.h>

namespace thread = std;

#ifdef WIN32
#include <boost/thread.hpp>

namespace thread = boost;
#endif

NixAlarm::NixAlarm()
{

}

void NixAlarm::annoyingBeep()
{
    system(NixAlarm::soundCmd);
    thread::this_thread::sleep_for(std::chrono::seconds(2));
}

void NixAlarm::beep()
{
    system(NixAlarm::beepCmd);
    thread::this_thread::sleep_for(std::chrono::seconds(2));
}
