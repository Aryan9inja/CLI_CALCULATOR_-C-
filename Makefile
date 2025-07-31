CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

TARGET = calculator

SRCS = main.c stack.c tokenizer.c
OBJS = $(SRCS:.c=.o)

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)