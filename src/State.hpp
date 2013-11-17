#ifndef STATE_HPP
#define STATE_HPP

#include <vector>
#include "Device.hpp"

class State
{
public:
    State();

    void clear();

    void addDevice(Device device);

    void removeDeviceById(IdType& id);

    const bool hasMassStorageDevice();

    const bool hasSmartphoneDevice();

    const int hidCount();

private:
    std::vector<Device> devices;

    const bool hasType(Device::Type type);
};

#endif // STATE_HPP
