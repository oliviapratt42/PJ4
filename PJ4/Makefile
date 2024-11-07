all :MAIN

MAIN	:main.o binarytree.o
	g++ -Wall -o MAIN main.o binarytree.o

main.o	:main.cpp main.h
	g++ -Wall -c main.cpp

binarytree.o	:binarytree.cpp binarytree.h
	g++ -Wall -c binarytree.cpp 

clean	:
	rm -f *.o MAIN

