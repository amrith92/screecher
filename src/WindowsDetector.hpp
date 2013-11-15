#ifndef WINDOWSDETECTOR_HPP
#define WINDOWSDETECTOR_HPP

#include "Detector.hpp"

class WindowsDetector : public Detector
{
public:
    explicit WindowsDetector();

    bool isHidRemoved();
};

#endif // WINDOWSDETECTOR_HPP
