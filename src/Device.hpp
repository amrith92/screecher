#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <stdint.h>

struct IdType
{
    uint16_t vendorId;
    uint16_t productId;
    uint16_t release; /* product release encoded in BCD */

    inline bool operator ==(const IdType& rhs)
    {
        if (this == &rhs) {
            return true;
        }

        if (this->vendorId != rhs.vendorId || this->productId != rhs.productId || this->release != rhs.release) {
            return false;
        }

        return true;
    }

    inline bool operator !=(const IdType& rhs)
    {
        return !(*this == rhs);
    }
};

class Device
{
public:
    enum Type {
        DEVICE_GENERIC, DEVICE_HID, DEVICE_MASS_STORAGE, DEVICE_SMARTPHONE
    };

    explicit Device(const IdType id, const Type deviceType);

    const IdType& getId() const;

    void setId(IdType id);

    const Type getType() const;

    void setType(Type deviceType);

    inline bool operator ==(const Device& rhs);

    inline bool operator !=(const Device& rhs);

protected:
    IdType theId;
    Type theDeviceType;
};

#endif // DEVICE_HPP
