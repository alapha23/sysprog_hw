CC = gcc

all: foo bar

foo: foo.o foo_dep1.o foo_dep2.o
	$(CC) foo.o foo_dep1.o foo_dep2.o -o foo
foo.o: foo.c	
	$(CC) -c foo.c
foo_dep1.o: foo_dep1.c
	$(CC) -c foo_dep1.c 
foo_dep2.o: foo_dep2.c
	$(CC) -c foo_dep2.c 

bar: bar.o bar_dep1.o bar_dep2.o
	$(CC) -o bar bar.o bar_dep1.o bar_dep2.o
bar.o: bar.c 
	$(CC) -c bar.c 
bar_dep1.o: bar_dep1.c
	$(CC) -c bar_dep1.c
bar_dep2.o: bar_dep2.c
	$(CC) -c bar_dep2.c
clean:
	rm *o main *.gch
