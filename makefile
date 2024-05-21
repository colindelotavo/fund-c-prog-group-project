# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I../include -Wall -Wextra -Werror

# Directories
SRC_DIR = src
INCLUDE_DIR = include
DATA_DIR = data
BUILD_DIR = build

# Source files
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/compression.c \
       $(SRC_DIR)/encryption.c \
       $(SRC_DIR)/fileio.c

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Executable
EXEC = $(BUILD_DIR)/task.out

# Default target
all: $(EXEC)

# Build executable
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

# Create build directory if it does not exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

# Run the program
run: $(EXEC)
	$(EXEC)

.PHONY: all clean run
