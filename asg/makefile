all: main
main: main.o add.o sub.o 
	gcc -o main main.o add.o sub.o
	
main.o: main.c
	gcc -c -o main.o main.c && gcc main.c -g -c -o gmain

add.o: add.c
	gcc -c -o add.o add.c && gcc add.c -g -c -o gadd

sub.o: sub.c
	gcc -c -o sub.o sub.c && gcc sub.c -g -c -o gsub

clear:
	rm -rf *.o
	rm -rf main
	rm -rf gmain
	rm -rf gadd
	rm -rf gsub
	
