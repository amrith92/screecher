#include "Detector.hpp"
#include <libusb.h>

bool Detector::isStorageDeviceConnected()
{
    libusb_device **devs;
    libusb_context *ctx = NULL;
    bool ret = false;

    if (libusb_init(&ctx) < 0) {
        throw "LIBUSB init error.";
    }

    libusb_set_debug(ctx, 3);

    ssize_t count = libusb_get_device_list(ctx, &devs);

    if (count < 0) {
        throw "Unable to open devices.";
    }

    libusb_device_descriptor description;
    for (ssize_t i = 0; i < count && !ret; ++i) {
        if (libusb_get_device_descriptor(devs[i], &description) < 0)
        {
            throw "LIBUSB error in device. Could not get description.";
        }

        if (LIBUSB_CLASS_MASS_STORAGE == description.bDeviceClass || LIBUSB_CLASS_PHYSICAL == description.bDeviceClass) {
            ret = true;
            break;
        }

        libusb_config_descriptor *config;
        libusb_get_config_descriptor(devs[i], 0, &config);

        const libusb_interface *interface;
        const libusb_interface_descriptor *interfaceDescriptor;

        for (int j = 0; j < (int) config->bNumInterfaces; ++j) {
            interface = &config->interface[j];

            for (int k = 0; k < interface->num_altsetting; ++k) {
                interfaceDescriptor = &interface->altsetting[k];

                if (LIBUSB_CLASS_MASS_STORAGE == interfaceDescriptor->bInterfaceClass || LIBUSB_CLASS_PHYSICAL == interfaceDescriptor->bInterfaceClass) {
                    ret = true;
                    break;
                }
            }
        }

        libusb_free_config_descriptor(config);
    }

    libusb_free_device_list(devs, 1);
    libusb_exit(ctx);

    return ret;
}
