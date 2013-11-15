TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/WindowsDetector.cpp \
    src/LinuxDetector.cpp \
    src/Alarm.cpp \
    src/Detector.cpp

HEADERS += \
    src/Device.hpp \
    src/Detector.hpp \
    src/Alarm.hpp \
    src/WindowsDetector.hpp \
    src/LinuxDetector.hpp \
    src/DetectorFactory.hpp

