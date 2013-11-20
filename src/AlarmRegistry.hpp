#ifndef ALARMREGISTRY_HPP
#define ALARMREGISTRY_HPP

#ifndef WIN32
# include "NixAlarm.hpp"
#else
# include "Alarm.hpp"
#endif

class AlarmRegistry
{
public:
    static Alarm *getAlarm()
    {
    	#ifdef WIN32
    	return new Alarm;
    	#else
    	return new NixAlarm;
    	#endif
    }
};

#endif // ALARMREGISTRY_HPP
