CC	= g++
CFLAGS	= -std=c++11 `pkg-config libusb-1.0 --cflags --libs`
WCFLGS	= -std=c++11 -lusb-1.0 -lboost_system -lboost_date_time -lboost_chrono -lboost_thread
RM	= rm -f
WRM	= del /F

SOURCES	= *.cpp
OBJS	= *.o

OUT	= bin/usbalarm
WOUT	= bin/usbalarm.exe

all: clean
	$(CC) src/$(SOURCES) -o $(OUT) $(CFLAGS)

win:
	$(CC) -DWIN32 src/$(SOURCES) -o $(WOUT) $(WCFLGS)

clean:
	$(RM) $(OUT) src/$(OBJS)

winclean:
	$(WRM) $(WOUT) src/$(OBJS)

.PHONY: all clean win winclean
