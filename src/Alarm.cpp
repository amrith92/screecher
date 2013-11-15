#include "Alarm.hpp"
#include <thread>
#include <chrono>
#include <iostream>

void Alarm::beep()
{
    for (short i = 0; i < 50; ++i) {
        std::cerr << "\a";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cerr << "\a\a";
    }
}

void Alarm::annoyingBeep()
{
    for (short i = 0; i < 50; ++i) {
        std::cerr << "\a\a\a";
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cerr << "\a";
    }
}
