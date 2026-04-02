CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Isrc

OS = $(shell uname -s)

ifeq ($(OS), Windows_NT)
	LFLAGS = -luser32 -lgdi32
	SRCOS_DIR = src/windows
	SRC_DIR = src
	OBJ_DIR = obj
	BIN_DIR = bin
	RM = del /Q /F
	TESTOS_DIR = test/windows
else
	LFLAGS = -lX11 -lXtst
	SRCOS_DIR = src/linux
	SRC_DIR = src
	OBJ_DIR = obj
	BIN_DIR = bin
	RM = rm -rf
	TESTOS_DIR = test/linux
endif


SRCS = $(wildcard $(SRCOS_DIR)/*.c $(SRC_DIR)/common.c)
OBJS = $(patsubst $(SRCOS_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/test_io
LIB_NAME = libioautomation.a
all: $(TARGET)



$(TARGET): $(OBJS) $(TESTOS_DIR)/test_keyboard.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRCOS_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR) $(BIN_DIR)

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