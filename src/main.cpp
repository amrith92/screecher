#include <iostream>
#include <chrono>
#include <thread>
#include <auto_ptr.h>
#include "Alarm.hpp"
#include "DetectorFactory.hpp"

using namespace std;

int main()
{
    cout << "USBALARAM start ... OK" << endl;

    Alarm alarm;
    std::auto_ptr<Detector> detector(DetectorFactory::getDetector("linux"));

    bool connected = false;
    while (true) {
        try {
            connected = detector.get()->isStorageDeviceConnected();
            cout << "STORAGE CONNECTED: " << boolalpha << connected << endl;

            if (connected) {
               alarm.annoyingBeep();
            }
        } catch (const char *e) {
            std::cerr << e << endl;
            break;
        }

        this_thread::sleep_for(chrono::seconds(5));
    }

    return 0;
}
