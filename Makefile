CC = gcc
CFLAGS = -c -Wall -Werror

all: my-cat my-sed my-uniq

my-cat: my-cat.o
	$(CC) -o my-cat my-cat.o

my-sed: my-sed.o
	$(CC) -o my-sed my-sed.o

my-uniq: my-uniq.o
	$(CC) -o my-uniq my-uniq.o

my-cat.o: my-cat.c
	$(CC) $(CFLAGS) my-cat.c

my-sed.o: my-sed.c
	$(CC) $(CFLAGS) my-sed.c

my-uniq.o: my-uniq.c
	$(CC) $(CFLAGS) my-uniq.c

clean:
	rm -f my-cat my-sed my-uniq *.o