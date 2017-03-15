CC=g++
CFLAGS=-I. -DLINUX
OBJ_PATH=obj/Linux/
BIN_PATH=bin/Linux/

all: $(OBJ_PATH)main.o
	$(CC) -o $(BIN_PATH)codeblocks-opener $(OBJ_PATH)main.o -I.

install: all
	./install-on-ubuntu.sh
