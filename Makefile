# Makefile for Recursively Compiling C++ Source Files

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++20

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Find all C++ source files in the directory and its subdirectories
SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.cpp')

# Generate a list of object files from source files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Executable name
EXECUTABLE = $(BIN_DIR)/main

# Create a list of unique subdirectories under OBJ_DIR
OBJ_SUBDIRS := $(sort $(dir $(OBJ_FILES)))

# Default target
all: $(EXECUTABLE)

# Rule to create the object directory and subdirectories if they don't exist
$(OBJ_SUBDIRS):
	mkdir -p $@

# Rule to compile C++ source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_SUBDIRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(EXECUTABLE)

.PHONY: all clean
