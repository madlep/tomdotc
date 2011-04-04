SOURCES=tom.c
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
CFLAGS=-Wall -g
LDFLAGS=
TARG=tom

all: $(TARG)

$(TARG): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARG)

.PHONY: all clean

