CC=gcc
CFLAGS=-Wall
SRC=src
BIN=bin
TARGET=$(BIN)/pomodoro

all: $(BIN) $(TARGET)
	@./$(TARGET)

$(BIN):
	mkdir -p $(BIN)

$(TARGET): $(SRC)/main.c $(SRC)/main.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)/main.c

run: all

clean:
	rm -rf $(BIN)

.PHONY: all run clean
