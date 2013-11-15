#ifndef DEVICE_HPP
#define DEVICE_HPP

class Device
{
public:
	explicit Device(Type deviceType);
	
	enum Type {
		DEV_USB_GENERIC, DEV_USB_STORAGE, DEV_USB_MOUSE, DEV_USB_KEYBOARD
	};
	
	inline void setType(Type deviceType)
	{
		this->theType = deviceType;
	}
	
	Type getType()
	{
		return this->theType;
	}

protected:
	Type theType;
};

#endif /* DEVICE_HPP */
