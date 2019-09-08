CC = gcc
CFLAGS = -Wall -Iincludes
TARGET = HW2.exe
SRCFILES = $(wildcard src/*.c)
OBJFILES = $(patsubst %.c,%.o,$(wildcard src/*.c))
DEPS = $(OBJFILES:.o=.d)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $@ $^

## or this?
-include $(DEPS)

## do I need ($DEPS) here?
%.o: %.c $(DEPS)
	$(CC) -c -o $(CFLAGS) $*.c $*.o
	$(CC) -MM $(CFLAGS) $*.c > $*.d

.PHONY: clean
clean:
	rm -f $(OBJFILES) $(DEPS)

.PHONY: rebuild
rebuild:
	rm -f $(TARGET)
	$(MAKE) clean
	$(MAKE) all
