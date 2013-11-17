#include "Device.hpp"

Device::Device(const IdType id, const Type deviceType)
{
    this->theId = id;
    this->theDeviceType = deviceType;
}

const IdType& Device::getId() const
{
    return this->theId;
}

void Device::setId(IdType id)
{
    this->theId = id;
}

const Device::Type Device::getType() const
{
    return this->theDeviceType;
}

void Device::setType(Type deviceType)
{
    this->theDeviceType = deviceType;
}

bool Device::operator ==(const Device& rhs)
{
    if (this == &rhs) {
        return true;
    }

    if (this->theDeviceType != rhs.getType()) {
        return false;
    }

    return (this->theId == rhs.getId());
}

bool Device::operator !=(const Device& rhs)
{
    return !(*this == rhs);
}
