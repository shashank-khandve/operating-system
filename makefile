//abc=gcc
all:main
main: main.o div.o mul.o
	gcc -o main main.o div.o mul.o
	
main.o: main.c
	gcc -c -o main.o main.c
	
div.o: div.c
	 gcc -c -o div.o div.c
	 
mul.o: mul.c
	 gcc -c -o mul.o mul.c
	 
clean:  
	rm -rf *.o
	rm -rf main
