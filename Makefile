CFLAGS= -Wall -Iinclude/ -g

test: test.c util.o
	gcc $^ $(CFLAGS) -o $@

util.o: src/util.c
	gcc -c -o $@ $< $(CFLAGS)


