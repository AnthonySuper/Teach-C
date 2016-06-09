CFLAGS= -Wall -Iinclude/ -g

test: test.c linear.o
	gcc $^ $(CFLAGS) -o $@

linear.o: src/inear.c
	gcc -c -o $@ $< $(CFLAGS)


