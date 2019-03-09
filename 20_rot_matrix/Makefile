CC = gcc
CFLAGS = -pedantic -std=gnu99 -Wall -Werror
EJOBS = $(wildcard *.o)
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))
rotate-matrix: $(OBJS)
	gcc -o $@ $(EJOBS)
clean:
	rm -f rotate-matrix rotate-matrix-debug *.o *.c~ *.h~
depend:
	makedepend $(SRCS)
	makedepend -a -o $(SRCS)

