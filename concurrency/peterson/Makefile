all: peterson

TLIB_PATH := ../thread-lib
CFLAGS := -I$(TLIB_PATH) -O2

peterson: peterson.c Makefile
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -f peterson
