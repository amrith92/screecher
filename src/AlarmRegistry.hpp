#ifndef ALARMREGISTRY_HPP
#define ALARMREGISTRY_HPP

#include <string>
#include "Alarm.hpp"
#include "NixAlarm.hpp"

class AlarmRegistry
{
public:
    static Alarm *getAlarm(std::string platform)
    {
        if (platform == "linux") {
            return new NixAlarm;
        }

        return new Alarm;
    }
};

#endif // ALARMREGISTRY_HPP
