#include "NixAlarm.hpp"
#include <thread>
#include <chrono>
#include <stdlib.h>

NixAlarm::NixAlarm()
{

}

void NixAlarm::annoyingBeep()
{
    system(NixAlarm::soundCmd);
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
