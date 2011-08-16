CC=gcc
CFLAGS= -c -g

main: main.o object.o people.o student.o
	$(CC) -g main.o object.o people.o student.o -o main

object.o:object.c
	$(CC) $(CFLAGS) object.c

people.o:people.c
	$(CC) $(CFLAGS) people.c

student.o:student.c
	$(CC) $(CFLAGS) student.c

main.o:main.c 
	$(CC) $(CFLAGS) main.c

clean:
	rm *.o
