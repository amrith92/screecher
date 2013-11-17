#ifndef DETECTOR_HPP
#define DETECTOR_HPP

class State;

class Detector
{
public:
    virtual void populateDeviceList(State *aState);
};

#endif /* DETECTOR_HPP */
