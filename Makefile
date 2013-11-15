CC	= g++
CFLAGS	= -std=c++11 `pkg-config libusb-1.0 --cflags --libs`
RM	= rm -f

SOURCES	= *.cpp
OBJS	= *.o

OUT	= bin/usbalarm

all: clean
	$(CC) src/$(SOURCES) -o $(OUT) $(CFLAGS)

clean:
	$(RM) $(OUT) src/$(OBJS)

.PHONY: all clean
