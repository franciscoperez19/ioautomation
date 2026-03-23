CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Isrc
LFLAGS = -lX11 -lXtst

SRCLINUX_DIR = src/linux
OBJ_DIR = obj
BIN_DIR = bin
TESTLINUX_DIR = test/linux

SRCS = $(wildcard $(SRCLINUX_DIR)/*.c)
OBJS = $(patsubst $(SRCLINUX_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/test_io
LIB_NAME = libioautomation.a
all: $(TARGET)



$(TARGET): $(OBJS) $(TESTLINUX_DIR)/test_mouse.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRCLINUX_DIR)/%.c
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