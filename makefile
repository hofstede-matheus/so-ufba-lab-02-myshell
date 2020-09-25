CC=gcc
CFLAGS = -std=c99 -Wall

define clean
    rm -f src/*.o
endef

myshell: src/myshell.c src/errors.o src/errors.h src/commands.o src/commands.h
	mkdir -p build
	$(CC) $(CFLAGS) src/myshell.c src/errors.o src/commands.o -o build/myshell

clean:
	rm -f src/*.o