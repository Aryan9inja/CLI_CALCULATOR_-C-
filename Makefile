CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

TARGET = calculator

SRCS = main.c token_stack.c tokenizer.c parser.c stack.c evaluator.c
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