#ifndef DETECTOR_HPP
#define DETECTOR_HPP

class Detector
{
public:
    virtual bool isStorageDeviceConnected();
	
    virtual bool isHidRemoved() = 0;
	
protected:
};

#endif /* DETECTOR_HPP */
