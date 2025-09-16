CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -L./vendors/raylib/build/raylib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TARGET = main
SRC_FILES = main.c config/config.c core/engine.c taskmanager/taskmanager.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CC) $(SRC_FILES) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)