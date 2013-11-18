#include "Alarm.hpp"
#include <thread>
#include <chrono>
#include <iostream>

namespace thread = std;

#ifdef WIN32
#include <boost/thread.hpp>

namespace thread = boost;
#endif

void Alarm::beep()
{
    for (short i = 0; i < 50; ++i) {
        std::cerr << "\a";
        thread::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cerr << "\a\a";
    }
}

void Alarm::annoyingBeep()
{
    for (short i = 0; i < 50; ++i) {
        std::cerr << "\a\a\a";
        thread::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cerr << "\a";
    }
}
