CC = gcc
CFLAGS = -c -std=c89
OBJS = main.o ext_file.o

all: main

main: $(OBJS)
	$(CC) main.o ext_file.o -o main
main.o: 
	$(CC) $(CFLAGS) main.c
ext_file.o:
	$(CC) $(CFLAGS) ext_file.c
gen_syb:
	readelf -s main.o > main.symtab

clean:
	rm *o main
