CC = gcc
CFLAGS = -Wall -I./include
LDFLAGS = -L./lib -lserver -lm -pthread

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
EXECUTABLE = $(BIN_DIR)/server

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
    $(CC) $(OBJ) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/server
