CC = cc
CFLAGS = -Wall -Wextra

build/main: main.c
	mkdir -p build
	$(CC) $< -o $@ $(CFLAGS)
debug: main.c
	$(CC) $< -o $@ $(CFLAGS) -fsanitize=address,undefined

.PHONY: clean
clean:
	rm build/main -f
	rm debug debug.exe -f
