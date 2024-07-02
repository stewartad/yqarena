CC := gcc
CFLAGS := -Wall -Werror

yqarena:
	$(CC) $(CFLAGS) -o yqarena.o -c src/yqarena.c
	ar -rcs libyqarena.a yqarena.o

test:
	$(CC) $(CFLAGS) -o test test.c src/yqarena.c

.PHONY: clean
	rm -f a.out yqarena.o

