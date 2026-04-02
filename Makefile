CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Isrc

ifeq ($(OS), Windows_NT)
	LFLAGS = -luser32 -lgdi32
	SRCOS_DIR = src/windows
	RM = rd /s /q
	TESTOS_DIR = test/windows
	TARGET = $(BIN_DIR)/test_io.exe
	MKDIR = if not exist $(subst /,\,$(1)) mkdir $(subst /,\,$(1))
else
	LFLAGS = -lX11 -lXtst
	SRCOS_DIR = src/linux
	RM = rm -rf
	TESTOS_DIR = test/linux
	TARGET = $(BIN_DIR)/test_io
	MKDIR = mkdir -p $(1)
endif

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(wildcard $(SRCOS_DIR)/*.c) $(SRC_DIR)/common.c
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

VPATH = $(SRCOS_DIR) $(SRC_DIR)

LIB_NAME = libioautomation.a
all: $(TARGET)



$(TARGET): $(OBJS) $(TESTOS_DIR)/test_keyboard.c
	@$(call MKDIR, $(BIN_DIR))
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR)/%.o: %.c
	@$(call MKDIR, $(OBJ_DIR))
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR) $(BIN_DIR)

test: all
	./$(TARGET)

lib:
	$(OBJS)
	@echo "Creating static library $(LIB_NAME)..."
	ar rcs $(LIB_NAME) $(OBJS)
	@echo "Done!"

install: lib
	@echo "Installing in usr/local/lib..."
	install -d /usr/local/lib
	install -m 644 $(LIB_NAME) /usr/local/lib/
	install -d /usr/local/include
	install -m 644 include/ioautomation.h /usr/local/include/
	@echo "Library installed succesfully"

.PHONY: all clean test lib install