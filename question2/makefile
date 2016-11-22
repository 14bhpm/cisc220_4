mystring.o: mystring.c mystring.h
	gcc -Wall -c mystring.c
main.o: main.c mystring.h
	gcc -Wall -c main.c
copier: main.o mystring.o
	gcc -Wall -o copier main.o mystring.o
