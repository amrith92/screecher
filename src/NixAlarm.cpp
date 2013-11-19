#include "NixAlarm.hpp"
#include <stdlib.h>

#ifdef WIN32
#define BOOST_THREAD_USE_LIB
#include <boost/chrono.hpp>
#include <boost/thread.hpp>

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
