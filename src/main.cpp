#include <iostream>
#include <chrono>
#include <thread>
#include <auto_ptr.h>
#include "AlarmRegistry.hpp"
#include "State.hpp"
#include "Detector.hpp"

using namespace std;

int main()
{
    cout << "USBALARAM start ... OK" << endl;

    auto_ptr<Alarm> alarm(AlarmRegistry::getAlarm("linux"));
    Detector detector;
    State initialState, aState;

    detector.populateDeviceList(&initialState);

    while (true) {
        try {
            aState.clear();
            detector.populateDeviceList(&aState);

            if (aState.hidCount() != initialState.hidCount()) {
                cout << "USBALARM: Mouse or Keyboard removed!" << endl;
                alarm.get()->beep();
            }

            initialState = aState;

            if (initialState.hasMassStorageDevice()) {
                cout << "USBALARM: Mass Storage device detected!" << endl;
                alarm.get()->annoyingBeep();
            }

            if (initialState.hasSmartphoneDevice()) {
                cout << "USBALARM: Mass Storage device detected!" << endl;
                alarm.get()->annoyingBeep();
            }
        } catch (const char *e) {
            cerr << e << endl;
            break;
        }

        this_thread::sleep_for(chrono::seconds(5));
    }

    return 0;
}
