CC	= g++
CFLAGS	= -std=c++11 `pkg-config libusb-1.0 --cflags --libs`
WCFLGS	= -std=c++11 -lusb-1.0 -lboost_system -lboost_date_time -lboost_chrono -lboost_thread
DEBUG	= -pg
RM	= rm -f
WRM	= del /F

SOURCES	= *.cpp
OBJS	= *.o

OUT	= bin/usbalarm
WOUT	= bin/usbalarm.exe

all: clean
	$(CC) src/$(SOURCES) -o $(OUT) $(CFLAGS)

debug: clean
	$(CC) src/$(SOURCES) -o $(OUT) $(DEBUG) $(CFLAGS)

win:
	$(CC) -DWIN32 src/$(SOURCES) -o $(WOUT) $(WCFLGS)

win-debug:
	$(CC) -DWIN32 src/$(SOURCES) -o $(WOUT) $(DEBUG) $(WCFLGS)

clean:
	$(RM) $(OUT) src/$(OBJS)

win-clean:
	$(WRM) $(WOUT) src/$(OBJS)

.PHONY: all clean win winclean debug win-debug
