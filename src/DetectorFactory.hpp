#ifndef DETECTORFACTORY_HPP
#define DETECTORFACTORY_HPP

#include "LinuxDetector.hpp"
#include "WindowsDetector.hpp"

class DetectorFactory
{
public:
    static Detector *getDetector(std::string platform)
    {
        if ("linux" == platform) {
            return new LinuxDetector();
        } else if ("windows" == platform) {
            return new WindowsDetector();
        }

        return nullptr;
    }
};

#endif // DETECTORFACTORY_HPP
