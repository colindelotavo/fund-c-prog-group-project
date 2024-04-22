# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Werror -ansi -lm

# Target executable
TARGET = encryption_program

# Source files and object files
SRCS = main.c caeser_cipher.c run_length.c
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to handle the main.c which might not have a corresponding header file
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean
