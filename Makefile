CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -L./vendors/raylib/build/raylib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TARGET = main
SRC = main.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)