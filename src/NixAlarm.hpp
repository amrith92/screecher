#ifndef NIXALARM_HPP
#define NIXALARM_HPP

#include "Alarm.hpp"

class NixAlarm : public Alarm
{
public:
    NixAlarm();

    virtual void annoyingBeep();

    virtual void beep();

protected:
    static constexpr char *soundCmd = "paplay /usr/share/sounds/freedesktop/stereo/alarm-clock-elapsed.oga";
    static constexpr char *beepCmd = "paplay /usr/share/sounds/freedesktop/stereo/suspend-error.oga";
};

#endif // NIXALARM_HPP
