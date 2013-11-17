#ifndef NIXALARM_HPP
#define NIXALARM_HPP

#include "Alarm.hpp"

class NixAlarm : public Alarm
{
public:
    NixAlarm();

    virtual void annoyingBeep();

protected:
    static constexpr char *soundCmd = "paplay /usr/share/sounds/freedesktop/stereo/alarm-clock-elapsed.oga";
};

#endif // NIXALARM_HPP
