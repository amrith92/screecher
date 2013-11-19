#include "NixAlarm.hpp"
#include <stdlib.h>

#ifdef WIN32
#include <boost/chrono.hpp>
#include <boost/thread.hpp>

#define BOOST_THREAD_USE_LIB

namespace thread = boost;
#else
#include <thread>
#include <chrono>

namespace thread = std;
#endif

NixAlarm::NixAlarm()
{

}

void NixAlarm::annoyingBeep()
{
    system(NixAlarm::soundCmd);
    thread::this_thread::sleep_for(thread::chrono::seconds(2));
}

void NixAlarm::beep()
{
    system(NixAlarm::beepCmd);
    thread::this_thread::sleep_for(thread::chrono::seconds(2));
}
