CC=gcc
CFLAGS= -g -Wall
OBJS=linkedlist.o

all: withlist witharray withwastearray

withlist:$(OBJS) main.c
	$(CC) $(CFLAGS) -DUSE_LINKED_LIST $^ -o $@

witharray:$(OBJS) main.c
	$(CC) $(CFLAGS)  $^ -o $@

withwastearray:$(OBJS) main.c
	$(CC) $(CFLAGS) -DWASTE_MEMORY $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main.o witharray withlist withwastearray