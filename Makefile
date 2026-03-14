CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Isrc
LFLAGS = -lX11 -lXtst

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/test_io

all: $(TARGET)

$(TARGET): $(OBJS) $(TEST_DIR)/*.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

test: all
	./$(TARGET)

.PHONY: all clean test