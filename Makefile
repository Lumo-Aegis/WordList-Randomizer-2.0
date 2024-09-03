# Compiler and flags for native Linux
CC = gcc
CFLAGS = -Wall -g

# Cross compiler for Windows (using MinGW-w64)
CC_WIN = x86_64-w64-mingw32-gcc
CFLAGS_WIN = -Wall -g

# Output directory and executable name
OUTPUT_NAME = WL-Randomizer

# Source files
SRC = src/*.c

# Targets
all: linux windows

#Compile for dev(delete later)
dev: $(SRC)
	$(CC) $(CFLAGS) -o $(OUTPUT_NAME) $(SRC) $(LDFLAGS)

# Compile for Linux
linux: $(SRC)
	mkdir -p $(OUTPUT_NAME)_linux
	$(CC) $(CFLAGS) -o $(OUTPUT_NAME)_linux/$(OUTPUT_NAME) $(SRC) $(LDFLAGS)

# Compile for Windows
windows: $(SRC)
	mkdir -p $(OUTPUT_NAME)_windows
	$(CC_WIN) $(CFLAGS_WIN) -o $(OUTPUT_NAME)_windows/$(OUTPUT_NAME).exe $(SRC) $(LDFLAGS_WIN)

# Clean up
clean:
	rm -rf $(OUTPUT_NAME)_linux $(OUTPUT_NAME)_windows $(OUTPUT_NAME)
