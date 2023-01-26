CC = gcc
CFLAGS = -Wall -Werror

all: my-cat my-sed my-uniq

my-cat:
	$(CC) -o my-cat my-cat.c $(CFLAGS)

my-sed:
	$(CC) -o my-sed my-sed.c $(CFLAGS)

my-uniq:
	$(CC) -o my-uniq my-uniq.c $(CFLAGS)

clean:
	rm -f my-cat my-sed my-uniq