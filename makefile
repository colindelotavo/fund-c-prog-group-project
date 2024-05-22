# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I./include -Wall -Wextra -Werror

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/compression.c \
       $(SRC_DIR)/encryption.c \
       $(SRC_DIR)/fileio.c

# Executable
EXEC = ./task.out

# Default target
all: $(EXEC)

# Build executable
$(EXEC): $(SRCS)
	$(CC) -o $(EXEC) $(SRCS) $(CFLAGS)

# Clean build files
clean:
	rm -rf $(EXEC)

# Run the program
run: $(EXEC)
	$(EXEC)

.PHONY: all clean run
