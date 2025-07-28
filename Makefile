CC = gcc
CFLAGS = -Wall
SRC = src
BIN = bin
TARGET = $(BIN)/pomodoro

all: $(BIN) $(TARGET)
	@echo "Build complete. Type your pomodoro command:"
	@read CMD; ./$(TARGET) $${CMD}

$(BIN):
	mkdir -p $(BIN)

$(TARGET): $(SRC)/main.c $(SRC)/main.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)/main.c

run: $(TARGET)
	@./$(TARGET)

clean:
	rm -rf $(BIN)

.PHONY: all run clean

