# Inventory Management System Makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
TARGET = inventory_system
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Source files
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/inventory.c $(SRCDIR)/database.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/inventory.o $(OBJDIR)/database.o
HEADERS = $(INCDIR)/inventory.h $(INCDIR)/database.h

# Default target
all: $(TARGET)

# Create object directory if it doesn't exist
$(OBJDIR):
	@if not exist $(OBJDIR) mkdir $(OBJDIR)

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo Build successful! Executable: $(TARGET).exe

# Clean build artifacts
clean:
	@if exist $(OBJDIR) rmdir /s /q $(OBJDIR)
	@if exist $(TARGET).exe del $(TARGET).exe
	@echo Clean completed!

# Install/Run
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Release build
release: CFLAGS += -O2 -DNDEBUG
release: $(TARGET)

# Help
help:
	@echo Available targets:
	@echo   all     - Build the project (default)
	@echo   clean   - Remove build artifacts
	@echo   run     - Build and run the program
	@echo   debug   - Build with debug symbols
	@echo   release - Build optimized release version
	@echo   help    - Show this help message

.PHONY: all clean run debug release help