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
LIB_NAME = libioautomation.a
all: $(TARGET)



$(TARGET): $(OBJS) $(TEST_DIR)/test_mouse.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

test: all
	./$(TARGET)

lib:
	@echo "Compiling objects..."
	$(CC) $(CFLAGS) -c src/*.c 
	@echo "Creating static lib $(LIB_NAME)"
	ar rcs $(LIB_NAME) *.o
	@rm *.o
	@echo "Done! Library in actual directory"

install: lib
	@echo "Installing in usr/local/lib..."
	install -d /usr/local/lib
	install -m 644 $(LIB_NAME) /usr/local/lib/
	install -d /usr/local/include
	install -m 644 include/ioautomation.h /usr/local/include/
	@echo "Library installed succesfully"

.PHONY: all clean test lib install