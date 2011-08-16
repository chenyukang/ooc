CC=gcc
CFLAGS= -c 

main: main.o object.o
	$(CC) main.o object.o -o main

object.o:object.c
	$(CC) $(CFLAGS) object.c

main.o:main.c 
	$(CC) $(CFLAGS) main.c

clean:
	rm *.o
