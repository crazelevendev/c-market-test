CC = cc
CFLAGS = -Wall -Wextra

build/main: main.c
	mkdir -p build
	$(CC) $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm build/main -f
