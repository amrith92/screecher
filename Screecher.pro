TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/Alarm.cpp \
    src/Detector.cpp \
    src/Device.cpp \
    src/State.cpp \
    src/NixAlarm.cpp

HEADERS += \
    src/Detector.hpp \
    src/Alarm.hpp \
    src/State.hpp \
    src/Device.hpp \
    src/NixAlarm.hpp \
    src/AlarmRegistry.hpp

