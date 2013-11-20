#include "Detector.hpp"
#include "State.hpp"
#include <libusb.h>
#include <string>
#include <iostream>

void Detector::populateDeviceList(State *aState)
{
    libusb_device **devs;
    libusb_context *ctx = NULL;

    if (libusb_init(&ctx) < 0) {    		
        throw "LIBUSB init error.";
    }

    libusb_set_debug(ctx, 3);

    ssize_t count = libusb_get_device_list(ctx, &devs);

    if (count < 0) {
        throw "Unable to open devices.";
    }

    IdType id;
    Device::Type type;
    unsigned char buffer[30];

    libusb_device_descriptor description;
    
    for (ssize_t i = 0; i < count; ++i) {
        if (libusb_get_device_descriptor(devs[i], &description) < 0)
        {
            throw "LIBUSB error in device. Could not get description.";
        }

        if (LIBUSB_CLASS_MASS_STORAGE == description.bDeviceClass || LIBUSB_CLASS_PHYSICAL == description.bDeviceClass) {
            type = Device::DEVICE_MASS_STORAGE;
        } else if (LIBUSB_CLASS_HID) {
            type = Device::DEVICE_HID;
        }

        /*{
            libusb_device_handle *handle;

            if (0 != libusb_open(devs[i], &handle)) {
                throw "LIBUSB error in device. Could not open.";
            }

            int size = 0;

            if ((size = libusb_get_string_descriptor_ascii(handle, description.iProduct, buffer, 30)) > 0) {
                std::string str;

                for (int _ = 0; _ < size; ++_) {
                    str += (char) buffer[_];
                }

                if (str == "Android") {
                    type = Device::DEVICE_SMARTPHONE;
                }
            }

            libusb_close(handle);
        }*/

        id.vendorId = description.idVendor;
        id.productId = description.idProduct;
        id.release = description.bcdDevice;

        if (id.vendorId == 0x04e8 && id.productId == 0x6860)
        {
            type = Device::DEVICE_SMARTPHONE;
        }

        libusb_config_descriptor *config; 
        if (0 == libusb_get_active_config_descriptor(devs[i], &config)) {
		      const libusb_interface *interface;
		      const libusb_interface_descriptor *interfaceDescriptor;

		      for (int j = 0; j < (int) config->bNumInterfaces; ++j) {
		          interface = &config->interface[j];

		          for (int k = 0; k < interface->num_altsetting; ++k) {
		              interfaceDescriptor = &interface->altsetting[k];

		              if (LIBUSB_CLASS_MASS_STORAGE == interfaceDescriptor->bInterfaceClass || LIBUSB_CLASS_PHYSICAL == interfaceDescriptor->bInterfaceClass) {
		                  type = Device::DEVICE_MASS_STORAGE;
		              }
		          }
		      }

		      libusb_free_config_descriptor(config);
        }

        aState->addDevice(Device(id, type));
    }

    libusb_free_device_list(devs, 1);
    libusb_exit(ctx);
}
