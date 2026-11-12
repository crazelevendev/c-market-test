CC = cc
CFLAGS = -Wall -Wextra -Iinclude

build/main: build/main.o build/buyer.o
	$(CC) $^ -o $@

build/main.o: main.c include/article.h include/buyer.h
	$(CC) -c $< -o $@ $(CFLAGS)

build/buyer.o: include/buyer.c include/buyer.h include/article.h
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm build/*.o build/main -f
