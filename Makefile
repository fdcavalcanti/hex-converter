CC = gcc
CFLAGS = -Wall -Wextra -std=c99
AR = ar
ARFLAGS = rcs

# Library files
LIB_NAME = libhex_to_rgb.a
LIB_SRC = hex_to_rgb.c
LIB_OBJ = hex_to_rgb.o
LIB_HEADER = hex_to_rgb.h

# Test program
TEST_SRC = test.c
TEST_OBJ = test.o
TEST_BIN = test

.PHONY: all clean library test

all: library test

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

clean:
	rm -f $(LIB_OBJ) $(LIB_NAME) $(TEST_OBJ) $(TEST_BIN)

