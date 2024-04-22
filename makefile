# makefile for generating edu_cybersec_tool.out
CC = gcc
CFLAGS = -Wall -Werror -ansi -lm

# Target executable
TARGET = my_program

# Source files and object files
SRCS = main.c caeser_cipher.c run_length.c
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean
