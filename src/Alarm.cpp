#include "Alarm.hpp"
#include <iostream>

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

void Alarm::beep()
{
    for (short i = 0; i < 50; ++i) {
        std::cerr << "\a";
        thread::this_thread::sleep_for(thread::chrono::milliseconds(500));
        std::cerr << "\a\a";
    }
}

void Alarm::annoyingBeep()
{
    for (short i = 0; i < 50; ++i) {
        std::cerr << "\a\a\a";
        thread::this_thread::sleep_for(thread::chrono::milliseconds(300));
        std::cerr << "\a";
    }
}
