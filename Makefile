CC	= g++
CFLAGS	= -std=c++11 `pkg-config libusb-1.0 --cflags --libs`
WCFLGS	= -std=c++11 -I %BOOST_INC% -I %LIBUSB_INC% -L %LIBUSB_LIB% -lusb
RM	= rm -f
WRM	= del

SOURCES	= *.cpp
OBJS	= *.o

OUT	= bin/usbalarm
WOUT	= bin/usbalarm.exe

all: clean
	$(CC) src/$(SOURCES) -o $(OUT) $(CFLAGS)

win: winclean
	$(CC) src/$(SOURCES) -o $(WOUT) $(WCFLGS)

clean:
	$(RM) $(OUT) src/$(OBJS)

winclean:
	$(WRM) $(WOUT) src/$(OBJS)

.PHONY: all clean win winclean
