CC = cc
CFLAGS = -Wall -Wextra

build/main: main.c
	$(CC) $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm build/main -f
