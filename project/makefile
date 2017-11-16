cc=gcc

main:main.o grep.o fdupes.o scandir.o
	gcc -o main  main.c grep.c fdupes.c scandir.c
	
main.o:main.c 
	gcc -c -o main.o main.c
	
grep.o:grep.c 
	gcc -c -o grep.o grep.c
	
fdupes.o:fdupes.c 
	gcc -c -o fdupes.o fdupes.c
	
scandir.o:scandir.c 
	gcc -c -o scandir.o scandir.c
	
clean:  
	rm -rf *.o
	rm -rf main
