all:main

main: main.o div.o mul.o
	gcc -o main main.o div.o mul.o
	
	
main.o: main.c
	gcc -c -o main.o main.c && gcc  main.c -g -c -o gmain
	
div.o: div.c
	 gcc -c -o div.o div.c && gcc div.c -g -c -o gdiv
	 
mul.o: mul.c
	 gcc -c -o mul.o mul.c && gcc mul.c -g -c -o gmul
	 
clean:  
	rm -rf *.o
	rm -rf main
	rm -rf gmain
	rm -rf gdiv
	rm -rf gmul

