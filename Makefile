CC	= g++
CFLAGS	= -std=c++11 `pkg-config libusb-1.0 --cflags --libs`
WCFLGS	= -std=c++11 -I$(BOOST_INC) -L$(BOOST_LIB) -I$(LIBUSB_INC) -L$(LIBUSB_LIB) -lusb-1.0 -lboost_system-mgw48-mt-1_55 -lboost_date_time-mgw48-mt-1_55 -lboost_chrono-mgw48-mt-1_55 -lboost_thread-mgw48-mt-1_55
RM	= rm -f
WRM	= del /F

SOURCES	= *.cpp
OBJS	= *.o

OUT	= bin/usbalarm
WOUT	= bin/usbalarm.exe

all: clean
	$(CC) src/$(SOURCES) -o $(OUT) $(CFLAGS)

win:
	$(CC) src/$(SOURCES) -o $(WOUT) $(WCFLGS)

clean:
	$(RM) $(OUT) src/$(OBJS)

winclean:
	$(WRM) $(WOUT) src/$(OBJS)

.PHONY: all clean win winclean
