CFLAGS= -Wall -Iinclude/ -g -lm

test: test.c linear.o
	gcc $^ $(CFLAGS) -o $@

linear.o: src/linear.c
	gcc -c -o $@ $< $(CFLAGS)


