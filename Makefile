# Target architecture: native (default) or riscv32
TARGET ?= native

# Compiler and tools selection based on target
ifeq ($(TARGET),riscv32)
    CC = riscv-none-elf-gcc
    AR = riscv-none-elf-ar
else
    CC = gcc
    AR = ar
endif

CFLAGS = -Wall -Wextra -std=c99 -Isrc
ARFLAGS = rcs

# Library files
LIB_NAME = libhex_to_rgb.a
LIB_SRC = src/hex_to_rgb.c
LIB_OBJ = hex_to_rgb.o
LIB_HEADER = src/hex_to_rgb.h

# Test program
TEST_SRC = test.c
TEST_OBJ = test.o
TEST_BIN = test

# Main program
MAIN_SRC = main.c
MAIN_OBJ = main.o
MAIN_BIN = main

.PHONY: all clean library test main

all: library test main

library: $(LIB_NAME)

$(LIB_NAME): $(LIB_OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(LIB_OBJ): $(LIB_SRC) $(LIB_HEADER)
	$(CC) $(CFLAGS) -c $(LIB_SRC) -o $(LIB_OBJ)

test: $(TEST_BIN)

$(TEST_BIN): $(TEST_OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST_OBJ) -L. -lhex_to_rgb -o $(TEST_BIN)

$(TEST_OBJ): $(TEST_SRC) $(LIB_HEADER)
	$(CC) $(CFLAGS) -c $(TEST_SRC) -o $(TEST_OBJ)

main: $(MAIN_BIN)

$(MAIN_BIN): $(MAIN_OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -L. -lhex_to_rgb -o $(MAIN_BIN)

$(MAIN_OBJ): $(MAIN_SRC) $(LIB_HEADER)
	$(CC) $(CFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

clean:
	rm -f $(LIB_OBJ) $(LIB_NAME) $(TEST_OBJ) $(TEST_BIN) $(MAIN_OBJ) $(MAIN_BIN)

