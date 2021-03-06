#include <iostream>
#include <memory>
#include "AlarmRegistry.hpp"
#include "State.hpp"
#include "Detector.hpp"

using namespace std;

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

int main()
{
    cout << "USBALARM start ... OK" << endl;

    auto_ptr<Alarm> alarm(AlarmRegistry::getAlarm());
    Detector detector;
    State initialState, aState;
    
    detector.populateDeviceList(&initialState);

    while (true) {
        try {
            aState.clear();
            detector.populateDeviceList(&aState);

            const int initHidCount = initialState.hidCount(), currentHidCount = aState.hidCount();

            if (currentHidCount < initHidCount) {
                cout << "USBALARM: Mouse or Keyboard removed!" << endl;
                alarm.get()->beep();
            } else if (currentHidCount > initHidCount) {
                cout << "USBALARM: Mouse or Keyboard added!" << endl;
                alarm.get()->beep();
            }

            if (aState.hasMassStorageDevice()) {
                cout << "USBALARM: Mass Storage device detected!" << endl;
                alarm.get()->annoyingBeep();
            }

            if (aState.hasSmartphoneDevice()) {
                cout << "USBALARM: Mass Storage device detected!" << endl;
                alarm.get()->annoyingBeep();
            }
        } catch (const char *e) {
            cerr << e << endl;
            break;
        }

        thread::this_thread::sleep_for(thread::chrono::seconds(5));
    }

    return 0;
}
