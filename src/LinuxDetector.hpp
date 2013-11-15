#ifndef LINUXDETECTOR_HPP
#define LINUXDETECTOR_HPP

#include "Detector.hpp"

class LinuxDetector : public Detector
{
public:
    explicit LinuxDetector();

    bool isHidRemoved();
};

#endif // LINUXDETECTOR_HPP
