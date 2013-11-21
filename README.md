USB Screecher
=============

A program that screeches when a USB MASS storage device
is attached to a protected computer.

It also keeps track of the number of Human Interface
devices (HIDs) attached to the computer, and squeals
if any new ones are removed or added.

On Windows, the alarm is generated through the CPU's
in-built speaker (via the audible-bell character), and
in *nix based system, leverages the freedesktop project's
sounds.

Notes
=====

## On building

#### Linux

Make sure you have the standard gcc/g++ toolchain installed
along with the make utility (usually bundled with the
distribution). On most platforms, run the following command
to install the required packages:

(On Debian-based systems)
```
sudo apt-get install build-essential
```

(On Red-Hat based systems)
```
sudo yum groupinstall "Development Tools"
```

###### LibUSB 1.0

This project uses the libusb-1.0 library for interacting
with USB devices from user-space. Make sure you have a copy the
dev branch installed in your system.

(On Debian-based systems)
```
sudo apt-get install libusb-1.0-0 libusb-1.0-0-dev
```

I'm unaware of similar packages being distributed on other
platforms, but if the packages aren't available on your distro
via the package manager like `yum` or `emerge`, then find
the project on [SourceForge](http://sourceforge.net/projects/libusb/)
and build it yourself.

###### Note on paplay

The freedesktop project's sounds which the NixAlarm class uses are
played back using the `paplay` program, which means that this
program expects you to be running the PulseAudio daemon and server
as your sound system abstraction.

###### Build

Once you have the toolchains installed, execute the following
commands to build it:

```
cd screecher && make
```

#### Windows

#### Dependencies

On Windows, there is an extra set of dependencies, namely:

1. Boost C++ Libraries (boost::thread and boost::chrono)
2. Libusbx Library (to provide a compatible interface to libusb-1.0,
   more so than libusb-win32)
3. Libusb-win32 (Optional; Install a binary version of the driver)

###### Libusbx

Grab a copy of the latest Windows binary of [libusbx from SourceForge](http://libusbx.sourceforge.net/).
Install the driver provided and copy over `libusb.h` to MinGW's include path
and `libusb-1.0.a` to MinGW's library path. (See the project's README for more information).

###### MSVC

This project uses the C++11 standard for quite a lot of the codebase
and things like `constexpr` are not fully supported in the MSVC
compiler. Until then, this official codebase will not support building
via the MSVC compiler. (You are free to modify the source to make it
work)

###### MinGW

There are a few issues with trying to build this with a vanilla MinGW
installation, as Boost has to built separately and made available in
MinGW's search path. If you have experience with building Boost yourself
then by all means, go ahead with this approach. For others, I recommend
you use [nuwen's MinGW distribution](http://nuwen.net/mingw.html), which
comes shrink-wrapped with a working Boost library, amongst git and other libraries,
and is natively x64.

In order to build the project, open up a shell (make sure that the MinGW
paths are set and Boost's too) and run:

```
cd screecher && make win
```
(Note that if you're using a vanilla MinGW distro, then use `mingw32-make`)

Fini, enjoy!

Made with ♥ at thegeekmachine

