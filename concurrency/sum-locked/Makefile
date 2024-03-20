all: sum
TLIB_PATH := ../thread-lib
CFLAGS := -O2 -I$(TLIB_PATH)

sum: sum.c Makefile
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -f sum
