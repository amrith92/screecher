#include "State.hpp"

State::State()
{

}

void State::clear()
{
    this->devices.clear();
}

void State::addDevice(Device device)
{
    this->devices.push_back(device);
}

void State::removeDeviceById(IdType& id)
{
    std::vector<Device>::iterator it, end = this->devices.end();

    for (it = this->devices.begin(); it != end; ++it) {
        if (id == it->getId()) {
            this->devices.erase(it);
            break;
        }
    }
}

const bool State::hasMassStorageDevice()
{
    return this->hasType(Device::DEVICE_MASS_STORAGE);
}

const bool State::hasSmartphoneDevice()
{
    return this->hasType(Device::DEVICE_SMARTPHONE);
}

const int State::hidCount()
{
    std::vector<Device>::const_iterator it, end = this->devices.end();
    int count = 0;

    for (it = this->devices.begin(); it != end; ++it) {
        if (it->getType() == Device::DEVICE_HID) {
            ++count;
        }
    }

    return count;
}

const bool State::hasType(Device::Type type)
{
    std::vector<Device>::const_iterator it, end = this->devices.end();

    for (it = this->devices.begin(); it != end; ++it) {
        if (it->getType() == type) {
            return true;
        }
    }

    return false;
}
