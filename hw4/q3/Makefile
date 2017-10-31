CC = gcc

main:
	$(CC) -c main.c 
	$(CC) -static -o main main.o ./mylib.a
lib: one.o two.o three.o
	ar rcs mylib.a one.o two.o three.o
one.o:
	$(CC) -c one.c 
two.o:
	$(CC) -c two.c
three.o:
	$(CC) -c three.c
clean:
	rm *.o main
