CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = contact_manager
SRCS = main.c contact.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) contacts.dat

.PHONY: all run clean